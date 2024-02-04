section .data

    hello   db 'Hello, World!', 0
    newline db 10          ; newline character

section .text

    global _start

_start:

    ; write Hello, World! to stdout

    mov rax, 1            ; syscall: write
    mov rdi, 1            ; file descriptor: stdout
    mov rsi, hello        ; pointer to the string
    mov rdx, 13           ; length of the string
    syscall              ; invoke syscall

    ; check for error

    cmp rax, 0            ; check if syscall returned an error
    jl  error_occurred    ; jump to error_occurred if there was an error

    ; write a newline character

    mov rax, 1            ; syscall: write
    mov rdi, 1            ; file descriptor: stdout
    mov rsi, newline      ; pointer to the newline character
    mov rdx, 1            ; length of the string
    syscall              ; invoke syscall

    ; check for error

    cmp rax, 0            ; check if syscall returned an error
    jl  error_occurred    ; jump to error_occurred if there was an error

    ; exit the program

    mov rax, 60           ; syscall: exit
    xor rdi, rdi          ; exit code 0
    syscall              ; invoke syscall

error_occurred:

    ; handle error here, e.g., print an error message and exit

    mov rax, 60           ; syscall: exit
    mov rdi, 1            ; file descriptor: stdout
    mov rsi, error_msg    ; pointer to the error message
    mov rdx, 13           ; length of the error message
    syscall              ; invoke syscall

    ; exit the program with an error code

    mov rax, 60           ; syscall: exit
    xor rdi, rdi          ; exit code 0
    inc rdi               ; set exit code to 1 for error
    syscall              ; invoke syscall

section .data

    error_msg db 'Error occurred!', 0