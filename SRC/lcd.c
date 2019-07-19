#include "lcd.h"

void send_command(unsigned char command_data) //��������
{
	unsigned char i;
	unsigned char i_data;
	unsigned int mbit;
	i_data = 0xF8; //���з�ʽ,���ݴ�MCU��LCD�������ڶ�λL�������ݿ���ָ�H������ʾ����
	mbit = (i_data & 0x80) >> 7;
	PTDD_PTDD6 = 1; //P1_0=1; //
	//DELAY_US(100);
	GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1;//PTDD_PTDD2=0;//P1_2=0;GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1
	DELAY_US(1);//�ӳ�1000us
	//PTADD_PTADD1=1;
	for (i = 0; i < 8; i++)
	{
		if (mbit == 1)
		{
			PTDD_PTDD3 = 1; //P1_1=(bit)(i_data&0x80);
		}

		if (mbit == 0)
		{
			GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;
		}
		//aa= (bool)((i_data&0x80)>>7);
		GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1;// PTDD_PTDD2=0; //P1_2=0;
		DELAY_US(1);//�ӳ�1000us
		PTDD_PTDD2 = 1; //P1_2=1;
		DELAY_US(1);//�ӳ�1000us
		i_data = i_data << 1;
		mbit = (i_data & 0x80) >> 7;
	}
	i_data = command_data;  //�����û�ָ��ָ��
	i_data &= 0xf0;
	mbit = (i_data & 0x80) >> 7;
	for (i = 0; i < 8; i++) //���͸�λ
	{
		if (mbit == 1)
		{
			PTDD_PTDD3 = 1; //P1_1=(bit)(i_data&0x80);
		}

		if (mbit == 0)
		{
			GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;
		} //aa=  (bool)(i_data&0x80);
		GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1;// PTDD_PTDD2=0;//P1_2=0;
		DELAY_US(1);//�ӳ�1000us
		PTDD_PTDD2 = 1; //P1_2=1;
		DELAY_US(1);//�ӳ�1000us
		i_data = i_data << 1;
		mbit = (i_data & 0x80) >> 7;
	}
	i_data = command_data;
	i_data <<= 4;
	mbit = (i_data & 0x80) >> 7;
	for (i = 0; i < 8; i++) //���͵�λ
	{
		if (mbit == 1)
		{
			PTDD_PTDD3 = 1; //P1_1=(bit)(i_data&0x80);
		}

		if (mbit == 0)
		{
			GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;
		}
		GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1;//PTDD_PTDD2=0;//P1_2=0;
		DELAY_US(1);//�ӳ�1000us
		PTDD_PTDD2 = 1;
		DELAY_US(1);//�ӳ�1000us
		i_data = i_data << 1;
		mbit = (i_data & 0x80) >> 7;
	}
	GpioDataRegs.GPBCLEAR.bit.GPIO57 = 1;//PTDD_PTDD6=0;//P1_0=0;
	DELAY_US(1);//delay_1ms(10);
}
//-----------------���������ӳ���-----------------------
void send_data(unsigned char command_data)
{
	unsigned char i;
	unsigned char i_data;
	unsigned int mbit;
	i_data = 0xfa;
	mbit = (i_data & 0x80) >> 7;
	PTDD_PTDD6 = 1; //P1_0=1;
	//Cpu_Delay100US;
	for (i = 0; i < 8; i++)
	{
		if (mbit == 1)
		{
			PTDD_PTDD3 = 1; //P1_1=(bit)(i_data&0x80);
		}

		if (mbit == 0)
		{
			GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;
		}
		GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1;//PTDD_PTDD2=0;
		DELAY_US(1);//�ӳ�1000us
		PTDD_PTDD2 = 1;
		DELAY_US(1);//�ӳ�1000us
		i_data = i_data << 1;
		mbit = (i_data & 0x80) >> 7;
	}
	i_data = command_data;
	i_data &= 0xf0;
	mbit = (i_data & 0x80) >> 7;
	for (i = 0; i < 8; i++)
	{
		if (mbit == 1)
		{
			PTDD_PTDD3 = 1; //P1_1=(bit)(i_data&0x80);
		}

		if (mbit == 0)
		{
			GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;
		}
		GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1;//PTDD_PTDD2=0;
		DELAY_US(1);//�ӳ�1000us
		PTDD_PTDD2 = 1;
		DELAY_US(1);//�ӳ�1000us
		i_data = i_data << 1;
		mbit = (i_data & 0x80) >> 7;
	}
	i_data = command_data;
	i_data <<= 4;
	mbit = (i_data & 0x80) >> 7;
	for (i = 0; i < 8; i++)
	{
		if (mbit == 1)
		{
			PTDD_PTDD3 = 1; //P1_1=(bit)(i_data&0x80);
		}

		if (mbit == 0)
		{
			GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;
		}
		GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1;//PTDD_PTDD2=0;
		DELAY_US(1);//�ӳ�1000us
		PTDD_PTDD2 = 1;
		DELAY_US(1);//�ӳ�1000us
		i_data = i_data << 1;
		mbit = (i_data & 0x80) >> 7;
	}
	GpioDataRegs.GPBCLEAR.bit.GPIO57 = 1;// PTDD_PTDD6=0;
	DELAY_US(1);//�ӳ�1000us
}
//-----------------------Һ����ʼ��------------------------
void lcd_init()
{
	asm(" EALLOW");
	GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 0;     // GPIO functionality GPIO48-GPIO63
	GpioCtrlRegs.GPBDIR.bit.GPIO54 = 1;      // GPIO32-GPIO63 are output
	GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0;     // GPIO functionality GPIO48-GPIO63
	GpioCtrlRegs.GPBDIR.bit.GPIO56 = 1;      // GPIO32-GPIO63 are output
	GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0;     // GPIO functionality GPIO48-GPIO63
	GpioCtrlRegs.GPBDIR.bit.GPIO57 = 1;      // GPIO32-GPIO63 are output
	asm(" EDIS");
	DELAY_US(100);
	send_command(0x30); //��������:һ����8λ����,����ָ�
	DELAY_US(5000);
	send_command(0x02); //��ַ��λ
	DELAY_US(5000);
	send_command(0x06);//���趨:��ʾ�ַ�/����������λ,DDRAM��ַ��1
	DELAY_US(5000);
	send_command(0x0c);//��ʾ�趨:����ʾ,��ʾ���,��ǰ��ʾλ��������
	DELAY_US(5000);
	send_command(0x01); //��DDRAM
	DELAY_US(5000);
	send_command(0x80); //����ʾ��ַ��Ϊ0X80,��Ϊ��һ�е���λ
	DELAY_US(5000);
}
//----------------------����λ����ʾһ������----------------
void hz_disp(unsigned char line, unsigned char row, unsigned char hz1, unsigned char hz2) //line��1-4��row��0-7��hz1���ֵĸ�8λ��hz2�����ֵĵ�8λ
{
	//send_command(0x01); // �����ʾ�������趨��ַָ��Ϊ00H
	switch (line)
	{
		case 1:
			{
				send_command(0x80 + row);
				send_data(hz1);
				send_data(hz2);
				break;
			}
		case 2:
			{
				send_command(0x90 + row);
				send_data(hz1);
				send_data(hz2);
				break;
			}
		case 3:
			{
				send_command(0x88 + row);
				send_data(hz1);
				send_data(hz2);
				break;
			}
		case 4:
			{
				send_command(0x98 + row);
				send_data(hz1);
				send_data(hz2);
				break;
			}
	}
}
//----------------------����λ����ʾ����----------------
void num_disp(unsigned char line, unsigned char row, unsigned char num, unsigned char numa, unsigned char numb, unsigned char numc) //line��1-4��row��0-7��numҪ��ʾ������
{
	//send_command(0x01); // �����ʾ�������趨��ַָ��Ϊ00H
	switch (line)
	{
		case 1:
			{
				send_command(0x80 + row);
				send_data(0x30 + num);
				send_data(0x30 + numa);
				send_data(0x30 + numb);
				send_data(0x30 + numc);
				break;
			}
		case 2:
			{
				send_command(0x90 + row);
				send_data(0x30 + num);
				send_data(0x30 + numa);
				send_data(0x30 + numb);
				send_data(0x30 + numc);
				break;
			}
		case 3:
			{
				send_command(0x88 + row);
				send_data(0x30 + num);
				send_data(0x30 + numa);
				send_data(0x30 + numb);
				send_data(0x30 + numc);
				break;
			}
		case 4:
			{
				send_command(0x98 + row);
				send_data(0x30 + num);
				send_data(0x30 + numa);
				send_data(0x30 + numb);
				send_data(0x30 + numc);
				break;
			}
	}

}
//----------------------����λ����ʾ����----------------
void strDisp(unsigned char line, unsigned char row, char str[], unsigned int count) //line��1-4��row��0-7��numҪ��ʾ������
{
	//send_command(0x01); // �����ʾ�������趨��ַָ��Ϊ00H
	switch (line)
	{
		case 1:
			{
				send_command(0x80 + row);
				break;
			}
		case 2:
			{
				send_command(0x90 + row);
				break;
			}
		case 3:
			{
				send_command(0x88 + row);
				break;
			}
		case 4:
			{
				send_command(0x98 + row);
				break;
			}
	}
	int i;
	int flag = 0;
	for (i = 0; i < count; ++i)
	{
		if (str[i] != '\0' && flag == 0)
		{
			send_data(str[i]);
		}
		else
		{
			flag = 1;
		}
	}
}
//LCD12864 ����*/
void LCD12864_Clear()
{
	send_command(0x01); //��DDRAM
	DELAY_US(5000);                //��ʱ1.6ms
}

/*����*/
qian_(int i)
{
	int k;
	k = i / 1000;
	return k;
}
bai_(int i)
{
	int k;
	k = i / 100 % 10;
	return k;
}
shi_(int i)
{
	int k;
	k = i / 10 % 10;
	return k;
}
ge_(int i)
{
	int k;
	k = i % 1000 % 100 % 10;
	return k;
}

/*��ʾ��ѹ1����ֵ*/
lcd_voltage1(i)
{

	hz_disp(1, 0, 0xB5, 0xE7);
	hz_disp(1, 1, 0xB3, 0xD8);
	hz_disp(1, 2, 0xB5, 0xE7);
	hz_disp(1, 3, 0xD1, 0xB9);

	num_disp(1, 4, bai_(i), 0x7E, shi_(i), ge_(i));

}
/*��ʾ��ѹ2����ֵ*/
lcd_voltage2(i)
{
	hz_disp(2, 0, 0xB5, 0xE7);
	hz_disp(2, 1, 0xB3, 0xD8);
	hz_disp(2, 2, 0xB5, 0xE7);
	hz_disp(2, 3, 0xC1, 0xF7);

	num_disp(2, 4, bai_(i), 0x7E, shi_(i), ge_(i));

}
/*��ʾ��ѹ3����ֵ*/
lcd_voltage3(i)
{
	hz_disp(3, 0, 0xCA, 0xE4);
	hz_disp(3, 1, 0xB3, 0xF6);
	hz_disp(3, 2, 0xB5, 0xE7);
	hz_disp(3, 3, 0xD1, 0xB9);

	num_disp(3, 4, bai_(i), 0x7E, shi_(i), ge_(i));

}
static char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void num2char1(char *str, double number, int g, int l)
{
	int i;
	int temp ;
	char str1;
	double t2 = 0.0;
	if (number >= 0)
	{
		temp = number / 1;
		str1 = ' ';
	}
	else
	{
		temp = -number / 1;
		str1 = '-';
	}
	for (i = 1; i <= g; i++)
	{
		if (temp == 0)
			str[g - i] = table[0];
		else
			str[g - i] = table[temp % 10];
		temp = temp / 10;
	}
	*(str + g) = '.';
	temp = 0;
	if (number >= 0)
	{
		t2 = number / 1;
	}
	else
	{
		t2 = -number / 1;
	}
	for (i = 1; i <= l; i++)
	{
		temp = t2 * 10;
		str[g + i] = table[temp % 10];
		t2 = t2 * 10;
	}
	*(str + g + l + 1) = '\0';
	send_command(0x80 + 4);
	send_data(str1);
	send_data(str[0]);
	send_data(str[1]);
	send_data(str[2]);
	send_data(str[3]);
	send_data(str[4]);
	send_data(str[5]);
}
void num2char2(char *str, double number, int g, int l)
{
	int i;
	int temp ;
	char str1;
	double t2 = 0.0;
	if (number >= 0)
	{
		temp = number / 1;
		str1 = ' ';
	}
	else
	{
		temp = -number / 1;
		str1 = '-';
	}
	for (i = 1; i <= g; i++)
	{
		if (temp == 0)
			str[g - i] = table[0];
		else
			str[g - i] = table[temp % 10];
		temp = temp / 10;
	}
	*(str + g) = '.';
	temp = 0;
	if (number >= 0)
	{
		t2 = number / 1;
	}
	else
	{
		t2 = -number / 1;
	}
	for (i = 1; i <= l; i++)
	{
		temp = t2 * 10;
		str[g + i] = table[temp % 10];
		t2 = t2 * 10;
	}
	*(str + g + l + 1) = '\0';
	send_command(0x90 + 4);
	send_data(str1);
	send_data(str[0]);
	send_data(str[1]);
	send_data(str[2]);
	send_data(str[3]);
	send_data(str[4]);
	send_data(str[5]);
}
void num2char3(char *str, double number, int g, int l)
{
	int i;
	int temp ;
	char str1;
	double t2 = 0.0;
	if (number >= 0)
	{
		temp = number / 1;
		str1 = ' ';
	}
	else
	{
		temp = -number / 1;
		str1 = '-';
	}
	for (i = 1; i <= g; i++)
	{
		if (temp == 0)
			str[g - i] = table[0];
		else
			str[g - i] = table[temp % 10];
		temp = temp / 10;
	}
	*(str + g) = '.';
	temp = 0;
	if (number >= 0)
	{
		t2 = number / 1;
	}
	else
	{
		t2 = -number / 1;
	}
	for (i = 1; i <= l; i++)
	{
		temp = t2 * 10;
		str[g + i] = table[temp % 10];
		t2 = t2 * 10;
	}
	*(str + g + l + 1) = '\0';
	send_command(0x88 + 4);
	send_data(str1);
	send_data(str[0]);
	send_data(str[1]);
	send_data(str[2]);
	send_data(str[3]);
	send_data(str[4]);
	send_data(str[5]);
}

