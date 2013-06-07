! @author: Charles Tim Batista Garrocho
! @contact: charles.garrocho@gmail.com
! @copyright: (C) 2013 Fortran Software Open Source

PROGRAM Dijkistra

    INTEGER :: INF=1000000, origem, destino, corrente, tamanho, menor_distancia, linha, coluna, verifica, indice, pos, pos_espaco
    INTEGER, DIMENSION(:, :), ALLOCATABLE :: matriz
    CHARACTER (LEN=32) :: argumento, arquivo
    CHARACTER*3000 :: dados_linha
    TYPE no
        INTEGER :: antecessor, distancia, processado
    END TYPE
    TYPE (no), DIMENSION(:), ALLOCATABLE :: caminho

    tamanho = IARGC()
    IF (tamanho == 3) THEN
        CALL GETARG(1, argumento)
        READ(argumento(1:), '(A)') arquivo
        CALL GETARG(2, argumento)
        READ(argumento(1:), '(i10)') origem
        CALL GETARG(3, argumento)
        READ(argumento(1:), '(i10)') destino
    ELSE
        PRINT*, 'Argumentos Inválidos... <Endereço da Matriz> <Nó de Origem> <Nó de Destino>'
        STOP
    END IF

    OPEN(UNIT=12, FILE=arquivo, IOSTAT=verifica)

    IF (verifica == 0) THEN

        ALLOCATE(matriz(1000, 1000))

        linha = 1
        coluna = 1

        DO
            READ(12,'(A)', IOSTAT=verifica) dados_linha
            IF (verifica < 0) EXIT

            pos = 1
            tamanho = 1

            DO
                IF ((dados_linha(pos+1:) == '').AND.(dados_linha(pos+2:) == '')) EXIT

                pos_espaco = index(dados_linha(pos:), ' ')
                READ(dados_linha(pos:pos+pos_espaco-2), '(i10)') matriz(linha, tamanho)
                tamanho = tamanho + 1
                pos = pos_espaco + pos
            END DO

            linha = linha + 1
        END DO

    ELSE
        PRINT *, 'Arquivo Inexistente...  ', arquivo
        STOP
    END IF

    CLOSE(12)

    IF ((origem > tamanho).OR.(origem < 1).OR.(destino > tamanho).OR.(destino < 1)) THEN
        PRINT *, 'Nó de Origem ou Destino Inválido...  '
        STOP
    END IF

    ALLOCATE(caminho(tamanho))

    DO indice = 1, tamanho
        caminho(indice)%antecessor = -1
        caminho(indice)%distancia = INF
        caminho(indice)%processado = 0
    END DO

    caminho(origem)%distancia = 0
    caminho(origem)%processado = 1

    corrente = origem
    linha = 1
    coluna = 1

   DO
        menor_distancia = INF
        IF (corrente == destino) EXIT

        DO indice = 1, tamanho
            IF (caminho(indice)%processado == 0) THEN
                IF (caminho(corrente)%distancia + matriz(corrente, indice) < caminho(indice)%distancia) THEN
                    caminho(indice)%antecessor = corrente
                    caminho(indice)%distancia = caminho(corrente)%distancia + matriz(corrente, indice)
                END IF
            END IF
        END DO

        corrente = 1

        DO indice = 1, tamanho
            IF ((caminho(indice)%processado == 0).AND.((caminho(indice)%distancia < menor_distancia))) THEN
                menor_distancia = caminho(indice)%distancia
                corrente = indice
            END IF
        END DO
        caminho(corrente)%processado = 1
    END DO
    
    DEALLOCATE(matriz)
    
    PRINT *, 'Origem: ', origem
    PRINT *, 'Destino: ', destino 
    PRINT *, 'Custo: ', caminho(destino)%distancia
    PRINT *, 'Caminho: '

    DO
        IF (destino == origem) EXIT
        PRINT *, caminho(destino)%antecessor
        destino = caminho(destino)%antecessor
    END DO

    DEALLOCATE(caminho)
END
