//14011094 nurullah çalýþkan
//28.11.2017 yapýlýþ tarihi

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct{
	int x;
	int y;
}points;
void kosekenarlar(points *point,int *ekxindis,int *ebxindis, int* ekyindis, int *ebyindis,int n){
	for(int i =1; i<n; i++){
		if(point[i].x>point[*ebxindis].x){
			*ebxindis=i;
		}
		if(point[i].x< point[*ekxindis].x){
			*ekxindis=i;
		}
		if(point[i].y>point[*ebyindis].y){	
			*ebyindis=i;
		}
		if(point[i].y<point[*ekyindis].y){
			*ekyindis=i;
		}
	}
}
void xmintoymax(points *p,int n, int ekxindis, int ebyindis,points *convexhull,int *m){
	int mm=0;
	float aci,opaci=0;
	bool sondurum=true;
	int i,hull=ekxindis,tmpindis=ekxindis;
		while((p[hull].y<p[ebyindis].y)and(sondurum==true)){
		opaci=0;
		sondurum=false;
		for(i=0; i<n; i++){
			if((p[i].x>=p[hull].x)and(p[i].x<=p[ebyindis].x)and(p[i].y>p[hull].y)and(p[i].y<p[ebyindis].y)){
				aci=(p[i].y-p[hull].y)/(p[i].x-p[hull].x);
				if(aci>opaci){
					opaci=aci;
					tmpindis=i;
					sondurum=true;					
			}		
	}
	}
	if(sondurum==true){	
	hull=tmpindis;
	convexhull[mm].x=p[hull].x;
	convexhull[mm].y=p[hull].y;
	mm++;
}
*m=mm;
}
}
void xmintoymin(points *p,int n, int ekxindis, int ekyindis,points *convexhull,int *m){
	float aci,opaci=0;
	bool sondurum=true;
	int i,hull=ekxindis,tmpindis=ekxindis,mm=0;
		while((p[hull].y>p[ekyindis].y)and(sondurum==true)){
		opaci=0;
		sondurum=false;
		for(i=0; i<n; i++){
			if((p[i].x>=p[hull].x)and(p[i].x<=p[ekyindis].x)and(p[i].y<p[hull].y)and(p[i].y>p[ekyindis].y)){
				aci=(p[hull].y-p[i].y)/(p[i].x-p[hull].x);
				if(aci>opaci){
					opaci=aci;
					tmpindis=i;
					sondurum=true;					
			}		
	}
	}
	if(sondurum==true){	
	hull=tmpindis;
	convexhull[mm].x=p[hull].x;
	convexhull[mm].y=p[hull].y;
	mm++;
}
*m=mm;
}

}
void xmaxtoymin(points *p,int n, int ebxindis, int ekyindis,points *convexhull,int *m){
int mm=0;
	float aci,opaci=0;
	bool sondurum=true;
	int i,hull=ebxindis,tmpindis=ebxindis;
	
		while((p[hull].y>p[ekyindis].y)and(sondurum==true)){
		opaci=0;
		sondurum=false;
		for(i=0; i<n; i++){
			if((p[i].x<p[hull].x)and(p[i].x>p[ekyindis].x)and(p[i].y<p[hull].y)and(p[i].y>p[ekyindis].y)){
				aci=(p[hull].y-p[i].y)/(p[hull].x-p[i].x);
				if(aci>opaci){
					opaci=aci;
					tmpindis=i;
					sondurum=true;					
			}		
	}
	}
	if(sondurum==true){	
	hull=tmpindis;
	
	convexhull[mm].x=p[hull].x;
	convexhull[mm].y=p[hull].y;
	mm++;

}
*m=mm;
}
}
void xmaxtoymax(points *p,int n, int ebxindis, int ebyindis,points *convexhull,int *m){
int mm=0;
	float aci,opaci=0;
	bool sondurum=true;
	int i,hull=ebxindis,tmpindis=ebxindis;
	
		while((p[hull].y<p[ebyindis].y)and(sondurum==true)){
		opaci=0;
		sondurum=false;
		for(i=0; i<n; i++){
			if((p[i].x<p[hull].x)and(p[i].x>p[ebyindis].x)and(p[i].y>p[hull].y)and(p[i].y<p[ebyindis].y)){
				aci=(p[i].y-p[hull].y)/(p[hull].x-p[i].x);
				
				
				if(aci>opaci){
					opaci=aci;
					tmpindis=i;
					sondurum=true;					
			}		
	}
	}
	if(sondurum==true){	
	hull=tmpindis;
	
	convexhull[mm].x=p[hull].x;
	convexhull[mm].y=p[hull].y;
	mm++;

}
*m=mm;
}
}
int main(){
	
	points *point,*solalt,*sagalt,*solust,*sagust;
	int i,n,ekxindis,ekyindis,ebxindis,ebyindis,m=0,abi=0,bci=0,cdi=0,dai=0;
	printf("Bu program convex hull koordinatlarini bulur");
	
	printf("\n kac koordinat gireceksiniz==>");
	scanf("%d",&n);

	point=(points*)malloc(n*sizeof(points));
	points convexhull[25];
	points mab[25];
	points mbc[25];
	points mcd[25];
	points mda[25];
	/*
		point[0].x=10;
	point[0].y=20;
		point[1].x=13;
	point[1].y=25;
		point[2].x=15;
	point[2].y=13;
		point[3].x=17;
	point[3].y=28;
		point[4].x=19;
	point[4].y=12;
		point[5].x=21;
	point[5].y=15;
		point[6].x=23;
	point[6].y=14;
		point[7].x=25;
	point[7].y=25;
		point[8].x=27;
	point[8].y=23;
		point[9].x=29;
	point[9].y=16;
		point[10].x=31;
	point[10].y=12;
		point[11].x=33;
	point[11].y=23,
		point[12].x=35;
	point[12].y=12;
		point[13].x=37;
	point[13].y=28;
		point[14].x=39;
	point[14].y=13;
		point[15].x=41;
	point[15].y=26;
		point[16].x=43;
	point[16].y=17;
		point[17].x=45;
	point[17].y=24;
		point[18].x=47;
	point[18].y=22;
		point[19].x=49;
	point[19].y=19;
		point[20].x=51;
	point[21].y=18;
		point[21].x=53;	
	point[21].y=17;
		point[22].x=55;
	point[22].y=24;
		point[23].x=57;
	point[23].y=23;
		point[24].x=59;
	point[24].y=22;
	*/
	
	printf("\n");
	for(i=0; i<n; i++){
		printf("\n%d. elemanin x degerini giriniz",i);
		scanf("%d",&point[i].x);
		printf("%d. elemanin y degerini giriniz",i);
		scanf("%d",&point[i].y);
	}
	
	ekxindis=0;
	ebxindis=0;
	ekyindis=0;
	ebyindis=0;
	
	printf("\n\nOnce kose koordinatlar buluyor...");
	kosekenarlar(point,&ekxindis,&ebxindis,&ekyindis,&ebyindis,n);
	printf("\nkose koordinatlar bulundu(%d,%d) (%d,%d) (%d,%d) (%d,%d)",
	point[ebxindis].x,point[ebxindis].y,point[ekxindis].x,point[ekxindis].y,point[ebyindis].x,point[ebyindis].y,point[ekyindis].x,point[ekyindis].y);
	

//

	printf("\nxmin ile ymin arasindaki convex hull bulunuyor");
	xmintoymin(point,n,ekxindis,ekyindis,mab,&abi);
	printf("\nxmin ile ymin arasindaki convex hull koordinatlar=>");
	for(i=0; i<abi; i++){
		printf("(%d,%d)",mab[i].x,mab[i].y);
	}
	printf("\n\nxmax ile ymin arasindaki convex hull bulunuyor");
	xmaxtoymin(point,n,ebxindis,ekyindis,mbc,&bci);
	printf("\nxmax ile ymin arasindaki convex hull koordinatlar=>");
	for(i=0; i<bci; i++){
		printf("(%d,%d)",mbc[i].x,mbc[i].y);
	}
	printf("\n\nxmin ile ymax arasindaki convex hull bulunuyor");
	xmintoymax(point,n,ekxindis,ebyindis,mcd,&cdi);
		printf("\nxmin ile ymax arasindaki convex hull koordinatlar=>");
	for(i=0; i<cdi; i++){
		printf("(%d,%d)",mcd[i].x,mcd[i].y);
	}
	printf("\n\nxmax ile ymax arasindaki convex hull bulunuyor");
	xmaxtoymax(point,n,ebxindis,ebyindis,mda,&dai);
		printf("\nxmax ile ymax arasindaki convex hull koordinatlar=>");
		for(i=0; i<dai; i++){
		printf("(%d,%d)",mda[i].x,mda[i].y);
	}

	return 0;
}
