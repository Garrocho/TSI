PROGRAM TESTE
    INTEGER :: verifica, fim
    CHARACTER*10 :: linha
    OPEN(5, FILE='./dados.txt', IOSTAT=verifica)
    IF (verifica == 0) THEN
        DO
            READ(5, '(A)', IOSTAT=fim) linha
            IF (fim < 0) EXIT
            PRINT *, linha
        END DO
    ELSE
        PRINT *, 'ERRO AO ABRIR O ARQUIVO'
    END IF
    CLOSE(5)
END PROGRAM
