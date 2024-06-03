
void Delay(unsigned int xms)
{
	unsigned int i=0,j=0;
	while(xms--)
	{
		for(i=0;i<2;i++)
		  for(j=0;j<128;j++);
	}
}

