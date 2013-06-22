void shift_bits(unsigned char* adr, int n, int shift)
{
	if ((n <= 0) || (shift <= 0))
		return;	//Не нужно ничего делать - либо некорректные данные
	for (size_t i = 0; i < shift; ++i)
	{	//цикл по количеству сдвигов (можно сдвиг, кратный длине char обработать отдельно)
		unsigned last_one = *(adr + n - 1) & 1;	//последний бит в цепочке. он станет первым
		for (size_t j = n - 1; ; --j)
		{	//цикл с конца цепочки
			if (j == 0)	
			{	//первый элемент цепочки - у него нет предыдущего, берём первый бит из last_one
				*adr = *adr >> 1;
				if (last_one)
					*adr = *adr + (1 << (sizeof(char) - 1));
				break;
			}
			else
			{
				unsigned previous_one = *(adr + j - 1) & 1;	//узнаю последний бит предыдущего байти в цепочке
				*(adr + j) = *(adr + j) >> 1;
				if (previous_one)
					*(adr + j) = *(adr + j) + (1 << (sizeof(char) - 1));
			}
		}
	}
}
