section .data
    hello_msg db 'Hello, World', 10 ; 10 is the ASCII code for newline
    msg_len equ $ - hello_msg   ; Calculate length of the message

section .text
    global main                 ; Use 'main' for gcc linking

main:
    ; syscall write(1, hello_msg, msg_len)
    mov rax, 1                  ; 1 = syscall number for write
    mov rdi, 1                  ; 1 = file descriptor for stdout
    mov rsi, hello_msg          ; rsi = pointer to the message
    mov rdx, msg_len            ; rdx = length of the message
    syscall                     ; Call the kernel. After this, rax = 13

    ; FIX: We must return 0 from main.
    xor rax, rax                ; Set rax = 0 (the exit code)
    ret                         ; Return to C runtime
