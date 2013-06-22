/*Shift Bits
Напишите функцию, которая циклически сдвигает биты в данной области памяти на указанное число позиций вправо (считаем, что младший бит следующего байта "соседствует" со старшим битом предыдущего).
Заголовок функции: void shift_bits(unsigned char* adr, int n, int shift).
adr - адрес первого байта области памяти, n - количество байт, shift - величина сдвига (>= 0).
Функцию main реализовывать не нужно.
Язык:gcc - GNU C 4.7.2
*/

/*void shift_bit (unsigned char *adr, bool first)
{
	*adr = *adr >> 1;
	if (first)
		*adr = *adr + (1 << (sizeof(char) - 1));
}*/

void shift_bits(unsigned char* adr, int n, int shift)
{
	if ((n <= 0) || (shift <= 0))
		return;	//Не нужно ничего делать - либо некорректные данные
	for (size_t i = 0; i < shift; ++i)
	{	//цикл по количеству сдвигов (можно сдвиг, кратный длине char обработать отдельно)
		bool last_one = *(adr + n - 1) & 1;	//последний бит в цепочке. он станет первым
		for (size_t j = n - 1; j >= 0; --j)
		{	//цикл с конца цепочки
			if (!j)	
			{	//первый элемент цепочки - у него нет предыдущего, берём первый бит из last_one
				//shift_bit (adr, last_one);
				*adr = *adr >> 1;
				if (last_one)
					*adr = *adr + (1 << (sizeof(char) - 1));
			}
			else
			{
				bool previous_one = *(adr + j - 1) & 1;	//узнаю последний бит предыдущего байти в цепочке
				//shift_bit (adr + j, previous_one);
				*(adr + j) = *(adr + j) >> 1;
				if (previous_one)
					*(adr + j) = *(adr + j) + (1 << (sizeof(char) - 1));
			}
		}
	}
}
