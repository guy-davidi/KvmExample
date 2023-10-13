#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/kvm.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>

int main() {
    int kvm_fd, vm_fd, vcpu_fd;
    void* guest_memory; // Use 'void*' for memory mapping

    kvm_fd = open("/dev/kvm", O_RDWR | O_CLOEXEC);
    if (kvm_fd == -1) {
        perror("Failed to open /dev/kvm");
        return 1;
    }

    vm_fd = ioctl(kvm_fd, KVM_CREATE_VM, 0);
    if (vm_fd == -1) {
        perror("Failed to create a virtual machine");
        close(kvm_fd);
        return 1;
    }

    const size_t memory_size = 0x100000;  // 1MB
    guest_memory = mmap(NULL, memory_size, PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANON | MAP_PRIVATE | MAP_FIXED | MAP_NORESERVE, -1, 0);
    if (guest_memory == MAP_FAILED) {
        perror("Failed to allocate memory for the virtual machine");
        close(vm_fd);
        close(kvm_fd);
        return 1;
    }

    vcpu_fd = ioctl(vm_fd, KVM_CREATE_VCPU, 0);
    if (vcpu_fd == -1) {
        perror("Failed to create a virtual CPU");
        munmap(guest_memory, memory_size);
        close(vm_fd);
        close(kvm_fd);
        return 1;
    }

    // Rest of your code

    // Cleanup
    close(vcpu_fd);
    munmap(guest_memory, memory_size);
    close(vm_fd);
    close(kvm_fd);

    return 0;
}
