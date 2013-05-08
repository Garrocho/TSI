PROGRAM TESTE
    INTEGER :: verifica, fim, arq = 10
    CHARACTER*10 :: linha
    OPEN(arq, FILE='./dados.txt', STATUS='OLD', ACCESS='SEQUENTIAL', IOSTAT=verifica)
    IF (verifica == 0) THEN
        DO
            READ(arq, '(A)', IOSTAT=fim) linha
            IF (fim < 0) EXIT
            PRINT *, linha
        END DO
    ELSE
        PRINT *, 'ERRO AO ABRIR O ARQUIVO'
    END IF
    CLOSE(arq)
END PROGRAM
