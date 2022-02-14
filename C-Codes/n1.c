#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct P{
	char lhs[3], rhs[10][10], first[20], follow[20], rfirst[10][20];
	int length[10], SP;
}P;
P P1[20];
int nop;
int f_Index(char ch){
	for(int i=0; i<nop; i++)
		if(P1[i].lhs[0] == ch)
		return i;
	return -1;
}

int IsNull(char *s){
	for(int i=0; i<strlen(s); i++)
		if(s[i]=='^')
		return 1;
	return 0;
}

void add_here(char ch, char *first){
	int j=0;
	for( ; j<strlen(first); j++)
	if(first[j]==ch)
	return;
	first[j++]=ch;
}

void fn_print(char *a1, char *a2, int null){
	if(null){
		for(int m=0; m<strlen(a1); m++)
			if(a1[m] != '^')
				add_here(a1[m], a2);
	}
	else{
		for(int m=0; m<strlen(a1); m++)
			add_here(a1[m], a2);
	}
}

void ForFirstSet(int a){
	int b;
		for(b=0; b<P1[a].SP; b++){
			 if(P1[a].rhs[b][0] == '^'){
			 	add_here(P1[a].rhs[b][0], P1[a].first);
 				add_here(P1[a].rhs[b][0], P1[a].rfirst[b]);
 			}
 			else if(!isupper(P1[a].rhs[b][0])){
 				add_here(P1[a].rhs[b][0], P1[a].first);
 				add_here(P1[a].rhs[b][0], P1[a].rfirst[b]);
 			}
 			else{
 				int l = 0, k, m;
 				while(l < strlen(P1[a].rhs[b])){
 					if(!isupper(P1[a].rhs[b][l])){
 						add_here(P1[a].rhs[b][l],P1[a].first);
 						add_here(P1[a].rhs[b][l],P1[a].rfirst[b]);
 						break;
 					}
 					k = f_Index(P1[a].rhs[b][l]);
 					if(IsNull(P1[k].first)){
 						fn_print(P1[k].first, P1[a].first, 1);
						fn_print(P1[k].first, P1[a].rfirst[b],1);
 						l++;
 					}
 					else{
 						fn_print(P1[k].first, P1[a].first, 0);
						fn_print(P1[k].first, P1[a].rfirst[b],0);
 						break;
 					}
 				}
 				if(l == strlen(P1[a].rhs[b])){
					 add_here('^', P1[a].first);
					 add_here('^', P1[a].rfirst[b]);
 				}
 		}
 	}
}

void ForFollowSet(int a){
 	if(a == 0)
 		P1[a].follow[0]='$';
 	int b, c, d;
 	for(b=0; b<nop; b++){
 		for(c=0; c<P1[b].SP; c++){
 			for(d=0; d<strlen(P1[b].rhs[c]); d++){
 				if(P1[b].rhs[c][d]==P1[a].lhs[0]){
					while(d<strlen(P1[b].rhs[c])){
 						if(P1[b].rhs[c][d+1] == 0 && P1[b].rhs[c][d] != P1[b].lhs[0]){
 							ForFollowSet(f_Index(P1[b].lhs[0]));
 							fn_print(P1[b].follow,P1[a].follow, 0);
 							break;
 						}
						else{
 							if(!isupper(P1[b].rhs[c][d+1])){
 								add_here(P1[b].rhs[c][d+1],P1[a].follow);
 								break;
 							}
							int pos = f_Index(P1[b].rhs[c][d+1]);
							if(IsNull(P1[pos].first)){
 								fn_print(P1[pos].first,P1[a].follow, 1);
 								d++;
 							}
 							else{
 								fn_print(P1[pos].first,P1[a].follow, 0);
 								break;
 							}
 						}
 					}
 				}
 			}
 		}
 	}
}
int main(){
 	int i, j;
	 printf("\n*** Program to find First and Follow set ***\n\n");
	 printf("----------------------------------------------------------");
 	 printf("\nEnter Total No of Productions : ");
	 scanf("%d", &nop);

	 for(i=0; i<nop; i++){
		 memset(P1[i].lhs, 0, sizeof(P1[i].lhs));
		 memset(P1[i].rhs, 0, sizeof(P1[i].rhs));
		 memset(P1[i].first, 0, sizeof(P1[i].first));
		 memset(P1[i].rfirst, 0, sizeof(P1[i].rfirst));
		 memset(P1[i].follow, 0, sizeof(P1[i].follow));
		 memset(P1[i].length, 0, sizeof(P1[i].length));
 	}
	for(i=0; i<nop; i++){
		printf("LHS of Production [%d] : ", i+1);
	 	scanf("%s", P1[i].lhs);
	 	printf("Enter Total No of Subproductions of P[%d] : ",i+1);
 		scanf("%d", &P1[i].SP);
 		for(j=0; j<P1[i].SP; j++){
 			printf("RHS of subproduction[%d] : ", j+1);
 			scanf("%s", P1[i].rhs[j]);
 			P1[i].length[j]=strlen(P1[i].rhs[j]);
 		}
 	}

	printf("----------------------------------------------------------");
 	printf("\nGrammar entered: \n");
 	for(i=0; i<nop; i++){
 		printf("%s -> ", P1[i].lhs);
 		for(j=0; j<P1[i].SP; j++){
 			if(j!=0)
 				printf(" | %s", P1[i].rhs[j]);
 			else
 				printf("%s", P1[i].rhs[j]);
 		}
 		printf("\n");
 	}
 
 	for(i=(nop-1); i>(-1); i--)
 		ForFirstSet(i);

 	for(i=0; i<nop; i++)
 		ForFollowSet(i);
	printf("----------------------------------------------------------");
 
 	printf("\nFIRST Sets : \n");
 	for(i=0; i<nop; i++){
 		printf("FIRST(%s) : ", P1[i].lhs);
 			for(j=0; j<strlen(P1[i].first); j++){
 					if(j != 0)
 						printf(", %c", P1[i].first[j]);
 					else
 						printf(" { %c", P1[i].first[j]);
 			}
 			printf(" }\n");
 	}
	printf("----------------------------------------------------------");
	printf("\nFOLLOW sets : \n");
 	for(i=0; i<nop; i++){
 		printf("FOLLOW(%s) : ", P1[i].lhs);
 			for(j=0; j<strlen(P1[i].follow); j++){
 				if(j != 0)
 					printf(", %c", P1[i].follow[j]);
 				else
 					printf("{ %c", P1[i].follow[j]);
 			}
 			printf(" }\n");
 	}
	printf("\n");
 	return 0;
}
