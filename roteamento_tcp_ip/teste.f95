PROGRAM TESTE
    INTEGER :: verifica, arq = 10
    OPEN(arq, FILE='./dados.txt', STATUS='OLD', ACCESS='SEQUENTIAL', IOSTAT=verifica)
    IF (verifica /= 0) THEN
        PRINT *, 'OK'
    ELSE
        PRINT *, 'ERRO AO ABRIR O ARQUIVO'
    END IF
    CLOSE(arq)
END PROGRAM
