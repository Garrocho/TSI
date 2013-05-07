program test_read

   implicit none
   integer, parameter :: VLI_K = selected_int_kind (18)
   integer, parameter :: DR_K = selected_real_kind (14)

   integer (VLI_K) :: i
   real (DR_K) :: a, b, c, d

   open (unit=15, file="dados.txt", status='old',    &
             access='sequential', form='formatted', action='read' )

   read (15, 110)  i, a, b, c, d
   110 format (I16, 4(1X, F10.0) )
   write (*, 120) i, a, b, c, d
   120 format ( I18, 4 (2X, F12.3) )

   read (15, *) i, a, b, c, d
   write (*, 120) i, a, b, c, d

end program test_read

PROGRAM TESTE
    IMPLICIT NONE

    CHARACTER(10) :: buffer
    INTEGER :: size

	OPEN(UNIT=10, FILE='./dados.txt', STATUS='OLD', ACTION='READ')
	READ (unit=10, "(A)", ADVANCE='NO', SIZE=size, EOR=10, END=20) buffer

	CLOSE(UNIT=10)

	PRINT*, buffer

END PROGRAM TESTE