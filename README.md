# KVM Virtualization Example
This is a simple example project demonstrating how to work with Kernel-based Virtual Machine (KVM) for virtualization in Linux.

Introduction
This project provides a basic example of working with KVM in Linux.
It includes a main.c file that demonstrates how to open a KVM device, create a virtual machine,
allocate memory for a guest, and set up a virtual CPU (vCPU).

## Getting Started
- A Linux-based system with KVM support.
- C compiler (e.g., GCC) for building the project.

## Compilation
- To compile the project, run the following command:
```
gcc -o main main.c
```
- Run the compiled program with superuser privileges to access /dev/kvm and create a virtual machine:

```
sudo ./main
```
The program will create a virtual machine, allocate memory, and set up a virtual CPU.

## Contributing
Contributions are welcome!
If you have ideas for improvements or would like to extend this project, feel free to fork the repository, make your changes, and submit a pull request.

License
This project is licensed under the MIT License.
