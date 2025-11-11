section .data
    hello_msg db 'Hello, World', 10 ; 10 is the ASCII code for newline
    msg_len equ $ - hello_msg   ; Calculate length of the message

section .text
    global main                 ; Use 'main' for gcc linking, not '_start'

main:
    ; syscall write(int fd, const void *buf, size_t count)
    mov rax, 1                  ; 1 = syscall number for write
    mov rdi, 1                  ; 1 = file descriptor for stdout
    mov rsi, hello_msg          ; rsi = pointer to the message
    mov rdx, msg_len            ; rdx = length of the message
    syscall                     ; Call the kernel

    ; No need to call exit (rax 60)
    ; GCC's C-runtime will handle that when main returns.
    ret
