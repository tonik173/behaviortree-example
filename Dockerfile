FROM ubuntu:latest

ARG USERNAME
ARG USERID
ARG GROUPID

# dev environment setup
RUN apt-get update
RUN apt-get install -y vim wget terminator iputils-ping apt-utils iproute2 
RUN apt-get install -y qtcreator qtbase5-dev qt5-qmake qtbase5-dev-tools
RUN apt-get install -y git build-essential cmake python3 libzmq3-dev libqt5svg5-dev
RUN apt-get install -y python3-pip

# install conan
RUN pip install conan --break-system-packages
RUN export PATH=$PATH:$HOME/.local/bin

# user setup
RUN groupadd ${USERNAME} --gid ${GROUPID} \
  && useradd -s /bin/bash --uid ${USERID} --gid ${GROUPID} -m ${USERNAME} \
  && mkdir /home/${USERNAME}/.config && chown ${USERID}:${GROUPID} /home/${USERNAME}/.config

# setup sudo
RUN apt-get update \
 && apt-get install -y sudo \
 && echo ${USERNAME} ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} \
 && chmod 0440 /etc/sudoers.d/${USERNAME} \
 && rm -rf /var/lib/apt/lists/*

# copy files and folders from host to container
COPY bashrc /home/${USERNAME}/.bashrc
COPY entrypoint.sh /entrypoint.sh

# mounted volume
RUN mkdir /home/${USERNAME}/behavior-tree-cpp/

# ownership
RUN chown -R ${USERID}:${GROUPID} /home/${USERNAME}
RUN chgrp -R ${USERNAME} /home/${USERNAME}

WORKDIR /home/${USERNAME}

# download Groot2
RUN wget https://s3.us-west-1.amazonaws.com/download.behaviortree.dev/groot2_linux_installer/Groot2-v1.6.1-linux-installer.run
RUN chmod +x Groot2-v1.6.1-linux-installer.run

# clone an build BehaviorTree.CPP
USER ${USERNAME}
RUN conan profile detect
RUN git clone https://github.com/BehaviorTree/BehaviorTree.CPP.git /home/${USERNAME}/BehaviorTree.CPP
RUN cd /home/${USERNAME} && \
    mkdir build && \
    cd build && \
    conan install ../BehaviorTree.CPP --output-folder=. --build=missing && \
    cmake ../BehaviorTree.CPP -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake" && \
    cmake --build .

USER root
ENTRYPOINT ["/bin/bash", "/entrypoint.sh"]
CMD ["bash"]
