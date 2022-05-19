#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Raþit Karabýyýk


bool karakter(char kar)
{
	if (kar == ' ' || kar == '+' || kar == '-' || kar == '*' ||
		kar == '/' || kar == ';' || kar == '>' || kar == ';' ||    //karakter ve operatör alýmý
		kar == '<' || kar == '=' || kar == '(' || kar == ')' ||
		kar == '[' || kar == ']' || kar == '{' || kar == '}' ||
		kar == '#' || kar == ',' || kar == '%' || kar == '.')
		return (true);
	return (false);
}

bool rakamlar(char rakam)
{
	if (rakam == '0' || rakam == '1' || rakam == '2' ||
		rakam == '3' || rakam == '4' || rakam == '5' ||					//rakam ve sayý operatör alýmý
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
  	scanf("%s",&metin);					//dosya yolu alýnýyor.

  	if((fp = fopen (metin, "r")) == NULL) {
    	printf("Dosya açma hatasý!");			//dosya yolu okunuyor.
       
    	exit(1);
     
  	}
	do{
		a=fgetc(fp);
  		if((int)a!=10&&(int)a!=32&&(int)a!=9){
  			dizi[i]=a;								//metinden veri alýnýyor eðerki boþluk yoksa diziye atýlýyor.
  			i++;
  		
  		}
  	
  		printf("%c",a);								//metin dosyasý yazdýrýlýyor
  	
  }
	while(a!=EOF);{
  		if((int)a!=10&&(int)a!=32&&(int)a!=9){
  			dizi[i]=a;
  			i++;
  												//döngü ile metinden tekrar veri alýnýyor eðerki boþluk yoksa diziye atýlýyor.
  		}
  
  }

	printf("\n");
  
 	i=0;
 	j=0;
	while(dizi[i]!=EOF){
		
		//dizi içindeki text dosyasýnýn karakterlerini konrtol eder. 			              
 		//Eðerki rakamsa,operatör yada karakterse fonksiyona gönderip hangisi olduðunu bulmaya çalýþýr.
		//Deðilse harfleri kontrol ederek tek tek yan yana yazdýrýr.
		//yazdýrýken , kullanarak tokenizer iþemini uygular.
		
	
		if(dizi[i]=='&'&&dizi[i+1]=='&'||dizi[i]=='|'&&dizi[i+1]=='|'||dizi[i]=='<'&&dizi[i+1]=='='||dizi[i]=='>'&&dizi[i+1]=='=' 
		||dizi[i]=='+'&&dizi[i+1]=='=' ||dizi[i]=='!'&&dizi[i+1]=='='||dizi[i]=='-'&&dizi[i+1]=='='||dizi[i]=='='&&dizi[i+1]=='='
		||dizi[i]=='*'&&dizi[i+1]=='=' ||dizi[i]=='/'&&dizi[i+1]=='=')
		{
				
		//==,&& gibi iki operatör yana yana olduðu durumlarýn bir kýsmýný  kontrol ediyor
			printf(",%c",dizi[i]);
 			printf("%c,",dizi[i+1]);
			i++;	
		}
		
		
 		else if(karakter(dizi[i])==true){        //dizinin[i] ninci elemanýný kontrol ediyor eðerki karakter yada operator ise döngüye giriyor
 
 
 			if(karakter(dizi[i+1])==true){
 				
 				//++,-- gibi iki operatör yana yana olduðu durumlarýn diðer kýsmýný kontrol ediyor kontrol ediyor
 				if(dizi[i]=='+'&&dizi[i+1]=='+'||dizi[i]=='-'&&dizi[i+1]=='-'||dizi[i]=='='&&dizi[i+1]=='='
			 	||dizi[i]=='+'&&dizi[i+1]=='=' ||dizi[i]=='!'&&dizi[i+1]=='='||dizi[i]=='-'&&dizi[i+1]=='='		
			 	||dizi[i]=='&'&&dizi[i+1]=='&' ||dizi[i]=='|'&&dizi[i+1]=='|'||dizi[i]=='<'&&dizi[i+1]=='='
				||dizi[i]=='>'&&dizi[i+1]=='=' ||dizi[i]=='*'&&dizi[i+1]=='='||dizi[i]=='/'&&dizi[i+1]=='=')
			 			//++,-- gibi iki operatör yana yana olduðu durumlarýn diðer kýsmýný kontrol ediyor kontrol ediyor
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
 					// eðerki iki karakter yan yana deðilse o karakteri  yazýyor.
 					//iki karakter yan yana gediðinde hata verebiliyor o yüzden- 
 					// 120 ve 148. satýrlar arasýnda opratör ve karakter arasýndaki virgül atamalarýný kontrol ediyor   
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
			 	}									//tek opratörü yazdýrýr ve 
			 										//fazladan virgül varsa onlarý diziden atar.
			 	else{
			 		printf(",%c,",dizi[i]);
			 	}
		 		
		 	}
 		
	 	}	
	 
	 	else if(rakamlar(dizi[j])==true){			//dizi[i] ninci elemaný rakam mý diye kontrol ediyor
	 	
	 		do
		 	{
				printf(",%c",dizi[j]);			// eðerki rakamsa sadece buraya giriyor
			}

	 	
	 		while(rakamlar(dizi[j]+1)==true);{			// eðer sayýysa tek tek rakamlarý burada kontrol ediyor
	 		
	 			printf("%c,",dizi[j+1]);
	 			j++;	
			}
		
 		
	 	}
	 
	 
	 	else{
		 
		 //deðiþkenleri yada for while  gibi komutlarý  yazdýrýyor
	 				 
			printf("%c",dizi[i]);
										
	 	}
	 	
 	i++;
 }

	fclose(fp);
	return (0);
}
