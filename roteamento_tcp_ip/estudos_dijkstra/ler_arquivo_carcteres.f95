PROGRAM ler_arquivo_carcteres
	IMPLICIT NONE
	CHARACTER (LEN=2000) :: conteudo
	INTEGER :: tamanho, controle
	OPEN(UNIT=1, FILE='matriz-212.dat', STATUS='OLD')
	tamanho = 0
	controle = 0
	DO
	    READ(1, '(A)', IOSTAT=controle) conteudo
	    IF (controle < 0) EXIT
	    WRITE(*, *) conteudo
	    tamanho = tamanho + 1
	ENDDO
	WRITE(*, *) tamanho
	CLOSE(1)
END
