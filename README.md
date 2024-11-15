# BehaviorTree.CPP examples

The examples in this repository run a simple wire cut and strip machine, using the [BehaviorTree.CPP](https://github.com/BehaviorTree/BehaviorTree.CPP) library.

![cut and strip illustration](cut-and-strip.drawio.svg)

## Using docker

The easiest way to play with the example is to run it with Docker. The docker file creates the latest Ubuntu image, installs a few development tools and clones and compiles [BehaviorTree.CPP](https://github.com/BehaviorTree/BehaviorTree.CPP).

1. Modifiy the `.env` file to match your environment. `HOST_ROOT_PATH` refers to the location of the clone of this repository.
2. Run docker

```sh
docker compose build
docker compose up -d
docker exec -itd btcpp-env terminator
# without an X-Window server just run
docker exec -it btcpp-env bash
```

If this works, the `Terminator` terminal app launches.

### Compile examples (within docker)

```sh
# change directory to demo, where demo is the name of the example
cd behavior-tree-cpp/<demo>  
mkdir build
# On WSL, I had to run the cmake command the first time with <sudo>. Someone knows how to fix this?
cmake -S ./src -B ./build    
cd build
make
# execute demo, where demo is the name of the example
./<demo> [path_to_tree.xml]  
```

### Playing with the BehaviorTree.CPP examples

```sh
cd ~/build/examples
./<example>
```

### Using Groot2

The docker image contains already the downloaded installer file in the home directory.
Launch the installer and follow the instructions.

Note: Using WSL2, I wasn't able to connect Groot2 with the tree execution app.

## More infos

- [BehaviorTree.CPP on GitHub](https://github.com/BehaviorTree/BehaviorTree.CPP)
- [BehaviorTree.CPP: Task Planning for Robots and Virtual Agents - Davide Faconti - CppCon 2023](https://youtu.be/7MZDBihsR_U?si=EExNL1-kruItlZ2h)
- [Introduction to Behavior Trees – YouTube playlist](https://www.youtube.com/playlist?list=PLFQdM4LOGDr_vYJuo8YTRcmv3FrwczdKg)
- [Robohub - Introduction to behavior trees](https://robohub.org/introduction-to-behavior-trees/)
- [Cornell University - Behavior Trees in Robotics and AI: An Introduction](https://arxiv.org/abs/1709.00084)
