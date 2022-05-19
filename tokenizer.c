#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Ra�it Karab�y�k


bool karakter(char kar)
{
	if (kar == ' ' || kar == '+' || kar == '-' || kar == '*' ||
		kar == '/' || kar == ';' || kar == '>' || kar == ';' ||    //karakter ve operat�r al�m�
		kar == '<' || kar == '=' || kar == '(' || kar == ')' ||
		kar == '[' || kar == ']' || kar == '{' || kar == '}' ||
		kar == '#' || kar == ',' || kar == '%' || kar == '.')
		return (true);
	return (false);
}

bool rakamlar(char rakam)
{
	if (rakam == '0' || rakam == '1' || rakam == '2' ||
		rakam == '3' || rakam == '4' || rakam == '5' ||					//rakam ve say� operat�r al�m�
		rakam == '6' || rakam == '7' || rakam == '8' || 
		rakam == '9'   )
		return (true);
	return (false);
}

int main()
{
	char metin[10000];
	char dizi[10000];
	int a;
	int i=0;
	int j=0;
  	FILE *fp;
  
  	printf(" Lutfen dosya yolu giriniz  ");
  	scanf("%s",&metin);					//dosya yolu al�n�yor.

  	if((fp = fopen (metin, "r")) == NULL) {
    	printf("Dosya a�ma hatas�!");			//dosya yolu okunuyor.
       
    	exit(1);
     
  	}
	do{
		a=fgetc(fp);
  		if((int)a!=10&&(int)a!=32&&(int)a!=9){
  			dizi[i]=a;								//metinden veri al�n�yor e�erki bo�luk yoksa diziye at�l�yor.
  			i++;
  		
  		}
  	
  		printf("%c",a);								//metin dosyas� yazd�r�l�yor
  	
  }
	while(a!=EOF);{
  		if((int)a!=10&&(int)a!=32&&(int)a!=9){
  			dizi[i]=a;
  			i++;
  												//d�ng� ile metinden tekrar veri al�n�yor e�erki bo�luk yoksa diziye at�l�yor.
  		}
  
  }

	printf("\n");
  
 	i=0;
 	j=0;
	while(dizi[i]!=EOF){
		
		//dizi i�indeki text dosyas�n�n karakterlerini konrtol eder. 			              
 		//E�erki rakamsa,operat�r yada karakterse fonksiyona g�nderip hangisi oldu�unu bulmaya �al���r.
		//De�ilse harfleri kontrol ederek tek tek yan yana yazd�r�r.
		//yazd�r�ken , kullanarak tokenizer i�emini uygular.
		
	
		if(dizi[i]=='&'&&dizi[i+1]=='&'||dizi[i]=='|'&&dizi[i+1]=='|'||dizi[i]=='<'&&dizi[i+1]=='='||dizi[i]=='>'&&dizi[i+1]=='=' 
		||dizi[i]=='+'&&dizi[i+1]=='=' ||dizi[i]=='!'&&dizi[i+1]=='='||dizi[i]=='-'&&dizi[i+1]=='='||dizi[i]=='='&&dizi[i+1]=='='
		||dizi[i]=='*'&&dizi[i+1]=='=' ||dizi[i]=='/'&&dizi[i+1]=='=')
		{
				
		//==,&& gibi iki operat�r yana yana oldu�u durumlar�n bir k�sm�n�  kontrol ediyor
			printf(",%c",dizi[i]);
 			printf("%c,",dizi[i+1]);
			i++;	
		}
		
		
 		else if(karakter(dizi[i])==true){        //dizinin[i] ninci eleman�n� kontrol ediyor e�erki karakter yada operator ise d�ng�ye giriyor
 
 
 			if(karakter(dizi[i+1])==true){
 				
 				//++,-- gibi iki operat�r yana yana oldu�u durumlar�n di�er k�sm�n� kontrol ediyor kontrol ediyor
 				if(dizi[i]=='+'&&dizi[i+1]=='+'||dizi[i]=='-'&&dizi[i+1]=='-'||dizi[i]=='='&&dizi[i+1]=='='
			 	||dizi[i]=='+'&&dizi[i+1]=='=' ||dizi[i]=='!'&&dizi[i+1]=='='||dizi[i]=='-'&&dizi[i+1]=='='		
			 	||dizi[i]=='&'&&dizi[i+1]=='&' ||dizi[i]=='|'&&dizi[i+1]=='|'||dizi[i]=='<'&&dizi[i+1]=='='
				||dizi[i]=='>'&&dizi[i+1]=='=' ||dizi[i]=='*'&&dizi[i+1]=='='||dizi[i]=='/'&&dizi[i+1]=='=')
			 			//++,-- gibi iki operat�r yana yana oldu�u durumlar�n di�er k�sm�n� kontrol ediyor kontrol ediyor
			 	{	
 					printf(",%c",dizi[i]);
 					printf("%c",dizi[i+1]);
 					i++;
			 	}
			 	else if(dizi[i]=='}'){
			 		printf("%c",dizi[i]);
			 		i++;
				 }
				  
 				else{
 					// e�erki iki karakter yan yana de�ilse o karakteri  yaz�yor.
 					//iki karakter yan yana gedi�inde hata verebiliyor o y�zden- 
 					// 120 ve 148. sat�rlar aras�nda oprat�r ve karakter aras�ndaki virg�l atamalar�n� kontrol ediyor   
 					if(i==0){
 							printf("%c",dizi[i]);
					 }
							
					 
 					else if(dizi[i]=='('&&dizi[i+1]==')'){
 						printf(",%c",dizi[i]);	
					 }
					 

					 else if(dizi[i]=='/'&&dizi[i+1]=='/'){
					 	printf(",%c",dizi[i]);	
					 }
 					else if(dizi[i]==')'){ 
					 
 						printf(",%c",dizi[i]);	
 						
					 }
					 else if(dizi[i]==';'&&dizi[i+1]=='}'){
					 	printf("%c",dizi[i]);	
					 
					 } 
					 else if(dizi[i]==';'&&dizi[i+1]=='/'){
					 	printf("%c",dizi[i]);	
					 
					 } 
					 else{
					 	printf(",%c,",dizi[i]);			
					 }
 			
			 	}
 			
 			
		 	}
		 		 	
		 	else{
		 			
		 	
		 		if(dizi[i+1]==','){
		 			printf("%c,",dizi[i]);			
			 	}									//tek oprat�r� yazd�r�r ve 
			 										//fazladan virg�l varsa onlar� diziden atar.
			 	else{
			 		printf(",%c,",dizi[i]);
			 	}
		 		
		 	}
 		
	 	}	
	 
	 	else if(rakamlar(dizi[j])==true){			//dizi[i] ninci eleman� rakam m� diye kontrol ediyor
	 	
	 		do
		 	{
				printf(",%c",dizi[j]);			// e�erki rakamsa sadece buraya giriyor
			}

	 	
	 		while(rakamlar(dizi[j]+1)==true);{			// e�er say�ysa tek tek rakamlar� burada kontrol ediyor
	 		
	 			printf("%c,",dizi[j+1]);
	 			j++;	
			}
		
 		
	 	}
	 
	 
	 	else{
		 
		 //de�i�kenleri yada for while  gibi komutlar�  yazd�r�yor
	 				 
			printf("%c",dizi[i]);
										
	 	}
	 	
 	i++;
 }

	fclose(fp);
	return (0);
}
