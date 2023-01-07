#include<iostream>
#include<chrono>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>
using namespace std;
using namespace std::chrono;
void SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),value);
}
bool rowcheck(char grid[][15], char words[],int count1,int grid1[][15])
 {
		 char test[15];
		int s=0;
		bool found=false;
		for(int y=0; y<15 && !found;y++)
					{
						for(int s=0,z=0;z<15 && !found ; z++)
						{
							test[s]=grid[y][z];
							s++;
						}
		
							for(int q=0;!found && q<=(15-count1); q++)
							{
								bool match= true;
								for(int k=0,j=q; k<count1 && match ; k++,j++)
								{
									if(test[j]!=words[k])
									match= false;
								}
								if(match)
								{
									found =true;
									for(int qa=1,i=q;qa<=count1;qa++,i++)
									{
										if(grid1[y][i]==0)
										{
										grid1[y][i]=1;
										}
 										else if(grid1[y][i]==1)
										{
											grid1[y][i]=2;
										}
										else if(grid1[y][i]==2){
											grid1[y][i]=3;
										}
									}
									 
								}
								else
								{
									found=false;
								}
							}

						}
	if(found)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
bool colcheck(char grid[][15],char words[],int count1,int grid1[][15])
{
	char test[15];
	int s=0;
	bool found=false;
	for(int y=0; y<15 && !found;y++)
					{
						for(int s=0,z=0;z<15 && !found;z++)
						{
							test[s]=grid[z][y];
							s++;
						}
						for(int q=0;!found && q<=(15-count1);q++)
							{
								bool match= true;
								for(int k=0,j=q; k<count1 && match ; k++,j++)
								{
									if(test[j]!=words[k])
									match= false;
								}
								if(match)
								{
									found= true;
 									for(int j=1, i=q;j<=count1;j++,i++)
									{
										if(grid1[i][y]==0)
										{
										grid1[i][y]=1;
										}
										else if(grid1[i][y]==1)
										{
											grid1[i][y]=2;
										}
										else if(grid1[i][y]==2){
											grid1[i][y]=3;
										}
									}
								}
								else
								{
									found =false;
								}
							}
						
						}
	if(found)
	{
		return true;
	}
 	else
	{
		return false; 
	}
}
bool diagcheck(char grid[][15],char words[], int count1,int grid1[][15])
{
	char test[15];
	int s=0;
	bool found=false;
	for(int x=0;x<15   && !found;x++)
					{
						for(int j=0;j<15 && !found;j++)
						{
							for(int s=0,n=x,y=j;n<15 && y<15 ; n++,y++)
							{
								test[s]=grid[n][y];

								s++;
							}
							for(int q=0;q<=(15-count1) && !found ;q++)
							{
								bool match= true;
								for(int k=0,j=q; k<count1 && match ;j++, k++)
								{ 
									if(test[j]!=words[k])
									match= false;
								}
								if(match)
								{
									found= true;
									int index=x+q;
									int z=j+q;
									for(int j=1,i=index;j<=count1;j++,i++,z++)
									{
										if(grid1[i][z]==0)
										{
										grid1[i][z]=1;
										}
										else if(grid1[i][z]==1)
										{
											grid1[i][z]=2;
										}
										else if(grid1[i][z]==2){
											grid1[i][z]=3;
										}
									}
								}
								else
								{
									found= false;
								}
							}
						
						}}
	if(found)
	{
		return true;
	}
	else
	{
		return false; 
	}

}
bool rowcheck1(char grid[][15], char words[],int count1,int grid1[][15])
{
	char test[15];
	int s=0;
	bool found=false;
	for(int y=0; y<15 && !found;y++)
					{
						for(int s=0,z=14;z>=0 && !found;z--)
						{
							test[s]=grid[y][z];
							s++;
						}
							
							for(int q=0;q<=(15-count1) && !found; q++)
							{
								bool match= true;
								for(int k=0,j=q; k<count1 && match ;j++, k++)
								{
									if(test[j]!=words[k])
									match= false;
								}
								if(match)
								{
									found= true;
									int index=14-q;
									for(int j=1,i=index ;j<=count1;j++,i--)
									{
										if(grid1[y][i]==0)
										{
										grid1[y][i]=1;
										}
										else if(grid1[y][i]==1)
										{
											grid1[y][i]=2;
										}
										else if(grid1[y][i]==2){
											grid1[y][i]=3;
										}
									}
								}
								else
								{
									found= false;
								}
							}
						
						}
	if(found)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
bool colcheck1(char grid[][15],char words[],int count1,int grid1[][15])
{
	char test[15];
	int s=0;
	bool found=false;
	for(int y=0; y<15 && !found;y++)
					{
						for(int s=0,k=14; k>=0; k--)
						{
							test[s]=grid[k][y];
							s++;
						}
						for(int q=0;q<=(15-count1) && !found; q++)
						{	
							bool match= true;
								for(int k=0,j=q; k<count1 && match ;j++, k++)
								{
									if(test[j]!=words[k])
									match= false;
								}
								if(match)
								{
									found= true;
									int index=14-q;
									for(int j=1,i=index;j<=count1;i--,j++)
									{
										if(grid1[i][y]==0)
										{
										grid1[i][y]=1;
										}
										else if(grid1[i][y]==1)
										{
											grid1[i][y]=2;
										}
										else if(grid1[i][y]==2){
											grid1[i][y]=3;
										}
									}
								}
					 			else
								{
									found= false;
								}
							}
						
						}
	if(found)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
bool diagcheck1(char grid[][15],char words[], int count1,int grid1[][15])
{
	char test[15];
	int s=0;
	bool found=false;
	for(int x=14;x>=0   && !found;x--)
					{
						for(int j=14;j>=0 && !found;j--)
						{
							for(int s=0,n=x,y=j;n>=0 && y>=0; n--,y--)
							{
								test[s]=grid[n][y];
								s++;
							}
							for(int q=0;q<=(15-count1) && !found ;q++)
							{
								bool match= true;
								for(int k=0,j=q; k<count1 && match ;j++, k++)
								{
									if(test[j]!=words[k])
									match= false;
								}
								if(match)
								{
									found= true;
									int index;
									index=j-q;
									int z=x-q;
									for(int k=1, i=index;k<=count1;i--,k++,z--)
									{
										if(grid1[z][i]==0)
										{
										grid1[z][i]=1;
										}
										else if(grid1[z][i]==1)
										{
											grid1[z][i]=2;
										}
										else if(grid1[z][i]==2){
											grid1[z][i]=3;
										}
									}
								}
								else
								{
									found= false;
								}
							}
						
						}}
	if(found)
	{
		return true;
	}
	else
	{
		return false; 
	}
 
}
bool diagcheck2(char grid[][15],char words[], int count1,int grid1[][15])
{

	char test[15];
	
	bool found=false;
	for(int x=0;x<15   && !found;x++)
					{
						for(int j=14;j>=0 && !found;j--)
						{	
							int s=0;
							for(int n=x,y=j;n<15 && y>=0;n++,y--)
							{
								test[s]=grid[n][y];
								s++;
							}
							for(int q=0;q<=(15-count1) &&!found ;q++)
							{
								
								bool match= true;
								for(int k=0,j=q; k<count1 && match ;j++, k++)
								{ 
									if(test[j]!=words[k])
									match= false;
								}
								if(match)
								{
									found= true;
									int k=j-q;
								    int z=x+q;
									for(int qa=1,i=k;qa<=count1;qa++,i--,z++)
									{
										if(grid1[z][i]==0)
										{
										grid1[z][i]=1;
										}
										else if(grid1[z][i]==1)
										{
											grid1[z][i]=2;
										}
										else if(grid1[z][i]==2){
											grid1[z][i]=3;
										}
									}
								}
								else
								{
									found= false;
								}
							}
						
						}}
	if(found)
	{
		return true;
	}
	else
	{
		return false; 
	}
	
}
bool diagcheck3(char grid[][15],char words[], int count1,int grid1[][15])
{
	char test[15];
	int u=0;
	bool found=false;
	for(int x=14;x>=0   && !found;x--)
					{
						for(int j=0;j<15 && !found;j++)
						{
							int s=0;
							for(int n=x,y=j;n>=0 && y<15;n--,y++)
							{
								test[s]=grid[n][y];
								s++;
							}
							u=s;
							for(int q=0;q<=(15-count1) && !found ;q++)
							{
								bool match= true;
								for(int k=0,j=q; k<count1 && match ;j++, k++)
								{
									if(test[j]!=words[k])
									match= false;
								}
								if(match)
								{
									found= true;
									int k=q+j;
								    int z=x-q;
									for(int qa=1,i=k;qa<=count1;qa++,i++,z--)
									{
										if(grid1[z][i]==0)
										{
										grid1[z][i]=1;
										}
										else if(grid1[z][i]==1)
										{
											grid1[z][i]=2;
										}
										else if(grid1[z][i]==2){
											grid1[z][i]=3;
										}
									}

								}
								else
								{
									found= false;
								}
							}
						
						}}
	if(found)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
void main()
{
	ifstream ifile("teleword.txt");
		if (ifile.fail())
		{
			cout<<"Your File is not opened"<<endl;
		}
		else
		{
			char grid[15][15];
			char words[500]={0};
			char sample[16]={0};
			char ch;
			int c=0;
			int s=0;
			int Wcount=0;
			int u=0;
			int count1=0;
			int grid1[15][15]={0};
			bool match1=true;
			char ch1;
			while(!ifile.eof())
			{
				ifile.get(ch);
				if(c==0)
				{
					
					for(int k=0;k<15;k++)
					{
						for(int y=0;y<15;y++)
						{
							if(ch!=' ')
							{
								grid[k][y]=ch;
							}
							ifile.get(ch);
							while(ch==32 || ch=='\n')
							{
								ifile.get(ch);
							}
						
						}
				   }
					c++;
				}
				if(c==1)
				{
					
					while(ch!='.')
					{
						if(ch>=97 && ch<=123)
						{
							ch=ch-32;
						}
						words[count1]=ch;
						ifile.get(ch);
						if(ch==',')
						{
							Wcount++;
						}
						count1++;
						s++;
					}
					words[count1]=ch;
					count1++;
					c++;
				}
			}
			for(int i=0;i<15;i++)
			{
				for(int j=0;j<15;j++)
				{
					cout<<grid[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
			for(int i=0;i<count1;i++)
			{
				cout<<words[i];
			}
			cout<<endl;
			cout<<endl;
			cout<<"Press S to Solve Puzzle at once"<<endl;
			cout<<"Press T to Solve Puzzle Step by Step"<<endl;
			cout<<"Press X to See Puzzle Statistics"<<endl;
			cin>>ch1;
			if(ch1=='S' || ch1=='s')
			{
			for(int nu=1;nu<=(Wcount+1);nu++)
			{
				char sample1[15]={0};
					int y=0;
					bool comma=false;
					for(int j=0, i=u;j<16 && !comma;j++,i++)
					{
						if(words[i]==',' || words[i]=='.' || words[i]==32 )
						{
							comma =true;}
						else{
						sample1[y]=words[i];
						y++;
						}
					 }
					u=u+(y+2);
					bool matched=rowcheck(grid,sample1,y,grid1);
					if(!matched)
					{
					   matched=colcheck(grid,sample1,y,grid1);
					   
					}
					if(!matched)
					{

						   matched=diagcheck(grid,sample1,y,grid1); 
						
					}
					if(!matched)
					{
							matched=rowcheck1(grid,sample1,y,grid1);
						
					}
					if(!matched)
					{
					   matched=colcheck1(grid,sample1,y,grid1); 
						
					}
					if(!matched)
					{
						   matched=diagcheck1(grid,sample1,y,grid1); 
						
					}
					if(!matched)
					{
						matched=diagcheck2(grid,sample1,y,grid1);
						
					}
					if(!matched)
					{
						matched=diagcheck3(grid,sample1,y,grid1);
						
					}
										
					}	
			char sample2[15]={0};
			int sa=0;
			
			for(int i=0;i<15;i++)
			{
				
				for(int j=0;j<15;j++)
				{
					if(grid1[i][j]==1)
				{
					SetColor(6);
					cout<<grid[i][j]<<" ";
				}
				else if(grid1[i][j]==2)
				{
					SetColor(1);
					cout<<grid[i][j]<<" ";
				}
				else if(grid1[i][j]==3)
				{
					SetColor(4);
					cout<<grid[i][j]<<" ";
				}
				else if(grid1[i][j]==0)
				{
					SetColor(7);
					cout<<grid[i][j]<<" ";
				  sample2[sa]=grid[i][j];
				  sa++;
				}
				}
				cout<<endl;
			}
			SetColor(7);
			cout<<"Teleword is: \t";
		for(int i=0;i<sa;i++)
		{
			
			cout<<sample2[i];
		}
		cout<<endl;
			}
			else if(ch1=='T' || ch1=='t')
			{
				int c2=0;
				for(int nu=1;nu<=(Wcount+1);nu++)
				{
					char sample1[15]={0};
					int y=0;
					char ch2;
					bool comma=false;
					for(int j=0, i=u;j<16 && !comma;j++,i++)
					{
						if(words[i]==',' || words[i]=='.' || words[i]==32 )
						{
							comma =true;}
						else{
						sample1[y]=words[i];
						y++;
						}
					 }
					u=u+(y+2);
					if(c2>0)
					{
						cout<<"\nPress Enter to see Next Word\n"<<endl;
						getch();
					}
					else{
						c2++;
					}
					bool matched=rowcheck(grid,sample1,y,grid1);
					if(matched)
					{
						for(int i=0;i<15;i++)
						{	
							for(int j=0;j<15;j++)
						{
							if(grid1[i][j]==1)
							{
								SetColor(6);
								cout<<grid[i][j]<<" ";
							}
							else if(grid1[i][j]==2)
							{
								SetColor(1);
								cout<<grid[i][j]<<" ";
							}
							else if(grid1[i][j]==3)
							{
								SetColor(4);
								cout<<grid[i][j]<<" ";
							}
							else if(grid1[i][j]==0)
							{
								SetColor(7);
								cout<<grid[i][j]<<" ";
							}
					}
						cout<<endl;
					SetColor(7);
						}
					
					}
					if(!matched)
					{
					   matched=colcheck(grid,sample1,y,grid1);
					   if(matched)
					   {
							for(int i=0;i<15;i++)
							{	
								for(int j=0;j<15;j++)
								{
									if(grid1[i][j]==1)
									{
										SetColor(6);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==2)
									{
										SetColor(1);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==3)
									{
										SetColor(4);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==0)
									{
										SetColor(7);
										cout<<grid[i][j]<<" ";
									}
							}
							cout<<endl;
							}
								SetColor(7); 
							}
					}
					if(!matched)
					{

						   matched=diagcheck(grid,sample1,y,grid1); 
						if(matched)
					   {
							for(int i=0;i<15;i++)
							{	
								for(int j=0;j<15;j++)
								{
									if(grid1[i][j]==1)
									{
										SetColor(6);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==2)
									{
										SetColor(1);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==3)
									{
										SetColor(4);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==0)
									{
										SetColor(7);
										cout<<grid[i][j]<<" ";
									}
							}
							cout<<endl;
							}
								SetColor(7); 
							}
					}
					if(!matched)
					{
							matched=rowcheck1(grid,sample1,y,grid1);
							if(matched)
					   {
							for(int i=0;i<15;i++)
							{	
								for(int j=0;j<15;j++)
								{
									if(grid1[i][j]==1)
									{
										SetColor(6);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==2)
									{
										SetColor(1);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==3)
									{
										SetColor(4);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==0)
									{
										SetColor(7);
										cout<<grid[i][j]<<" ";
									}
							}
							cout<<endl;
							}
								SetColor(7); 
							}
					}
					if(!matched)
					{
					   matched=colcheck1(grid,sample1,y,grid1); 
						if(matched)
					   {
							for(int i=0;i<15;i++)
							{	
								for(int j=0;j<15;j++)
								{
									if(grid1[i][j]==1)
									{
										SetColor(6);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==2)
									{
										SetColor(1);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==3)
									{
										SetColor(4);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==0)
									{
										SetColor(7);
										cout<<grid[i][j]<<" ";
									}
							}
							cout<<endl;
							}
								SetColor(7); 
							}
					}
					if(!matched)
					{
						   matched=diagcheck1(grid,sample1,y,grid1); 
							if(matched)
					   {
							for(int i=0;i<15;i++)
							{	
								for(int j=0;j<15;j++)
								{
									if(grid1[i][j]==1)
									{
										SetColor(6);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==2)
									{
										SetColor(1);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==3)
									{
										SetColor(4);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==0)
									{
										SetColor(7);
										cout<<grid[i][j]<<" ";
									}
							}
							cout<<endl;
							}
								SetColor(7); 
							}	
					}
					if(!matched)
					{
						matched=diagcheck2(grid,sample1,y,grid1);
						if(matched)
					   {
							for(int i=0;i<15;i++)
							{	
								for(int j=0;j<15;j++)
								{
									if(grid1[i][j]==1)
									{
										SetColor(6);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==2)
									{
										SetColor(1);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==3)
									{
										SetColor(4);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==0)
									{
										SetColor(7);
										cout<<grid[i][j]<<" ";
									}
							}
							cout<<endl;
							}
								SetColor(7); 
							}					}
					if(!matched)
					{
						matched=diagcheck3(grid,sample1,y,grid1);
						if(matched)
					   {
							for(int i=0;i<15;i++)
							{	
								for(int j=0;j<15;j++)
								{
									if(grid1[i][j]==1)
									{
										SetColor(6);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==2)
									{
										SetColor(1);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==3)
									{
										SetColor(4);
										cout<<grid[i][j]<<" ";
									}
									else if(grid1[i][j]==0)
									{
										SetColor(7);
										cout<<grid[i][j]<<" ";
									}
							}
							cout<<endl;
							}
								SetColor(7); 
							}
					}
					
										
					}
					cout<<"\nTeleword is\t";
				for(int i=0;i<15;i++)
				{
					for(int j=0;j<15;j++)
					{
						if(grid1[i][j]==0)
							cout<<grid[i][j];
					}
				}
				cout<<endl;
			}
			else if(ch1=='X' || ch1=='x')
			{
				int Rfor=0,Rbac=0,Cfor=0,Cbac=0,Dfor=0,Dbac=0,R=0,C=0,D=0,telecount=0;
				int max,min,sum=0;
				int c1=0;
				auto start= high_resolution_clock::now();
				for(int nu=1;nu<=(Wcount+1);nu++)
			   {
				char sample1[15]={0};
					int y=0;
					bool comma=false;
					for(int j=0, i=u;j<16 && !comma;j++,i++)
					{
						if(words[i]==',' || words[i]=='.' || words[i]==32 )
						{
							comma =true;}
						else{
						sample1[y]=words[i];
						y++;
						}
					 }
					u=u+(y+2);
					sum=sum+y;
					if(c1>0)
					{
						if(y>max)
						{
							max=y;
						}
						if(y<min)
						{
							min=y;
						}
					}
					else{
						max=y;
						min=y;
						c1++;
					}
					bool matched=rowcheck(grid,sample1,y,grid1);
					if(matched)
					{
						Rfor++;
						R++;
					}
					if(!matched)
					{
					   matched=colcheck(grid,sample1,y,grid1);
					   if(matched)
					   {
							C++;
						   Cfor++;
					   }
					}
					if(!matched)
					{
						   matched=diagcheck(grid,sample1,y,grid1); 
						if(matched)
					   {
						   D++;
							Dfor++;
					   }	
					}
					if(!matched)
					{
							matched=rowcheck1(grid,sample1,y,grid1);
							if(matched)
					   {
						   R++;
							Rbac++;
					   }						
					}
					if(!matched)
					{
					   matched=colcheck1(grid,sample1,y,grid1); 
						if(matched)
					   {
						   C++;
							Cbac++;
					   }
					}
					if(!matched)
					{
						   matched=diagcheck1(grid,sample1,y,grid1); 
						if(matched)
					   {
						   D++;
							Dbac++;
					   }
					}
					if(!matched)
					{
						matched=diagcheck2(grid,sample1,y,grid1);
						if(matched)
					   {
						   D++;
							Dfor++;
					   }
			  		}
					if(!matched)
					{
						matched=diagcheck3(grid,sample1,y,grid1);
						if(matched)
					   {
						   D++;
							Dbac++;
					   }
					}
										
					}
					auto stop= high_resolution_clock::now();
					auto timeTaken= duration_cast<microseconds>(stop-start);
			char sample2[15]={0};
			int sa=0;
			
			for(int i=0;i<15;i++)
			{
				
				for(int j=0;j<15;j++)
				{
					if(grid1[i][j]==1)
				{
					SetColor(6);
					cout<<grid[i][j]<<" ";
				}
				else if(grid1[i][j]==2)
				{
					SetColor(1);
					cout<<grid[i][j]<<" ";
				}
				else if(grid1[i][j]==3)
				{
					SetColor(4);
					cout<<grid[i][j]<<" ";
				}
				else if(grid1[i][j]==0)
				{
					SetColor(7);
					cout<<grid[i][j]<<" ";
				  sample2[sa]=grid[i][j];
				  sa++;
				}
				}
				cout<<endl;
			}
			SetColor(7);
			cout<<"Teleword is: \t";
		for(int i=0;i<sa;i++)
		{
			
			cout<<sample2[i];
 		}
		cout<<endl;
		
		int ij=0;
		while(ij<15)
		{
			int ji=0;
			while(ji<15)
			{
				if(grid1[ij][ji]==0)
				{
					telecount++;
					ij++;
					ji=-1;
				}
				ji++;
			}
			ij++;
		}
		int rmax=0,a1,b1, cmax=0;
		for(int i=0;i<15;i++)
		{
			int sum=0;
			for(int j=0;j<15;j++)
			{
				sum=grid1[i][j];
			}
			if(sum>rmax)
			{s
			rmax=sum;
			a1=i;
			}
		}
		for(int i=0;i<15;i++)
		{
	       int sum=0;
			for(int j=0;j<15;j++)
			{
				sum=grid1[j][i]
			}
			if(sum>cmax)
			{
			cmax=sum;
			b1=i;
			}
		}
		cout<<"Time Taken  "<<timeTaken.count() <<"microseconds"<<endl;
		cout<<"Longest Word length:  "<<max<<endl;
		cout<<"Shortest Word length:  "<<min<<endl;
		cout<<"Average Word length:  "<<(sum/(Wcount+1))<<endl;
		cout<<"Horizontal:  "<<R<<" "<<"{"<<Rfor<<","<<Rbac<<"}"<<endl;
		cout<<"Vertical:  "<<C<<" "<<"{"<<Cfor<<","<<Cbac<<"}"<<endl;
		cout<<"Diagonal:  "<<D<<" "<<"{"<<Dfor<<","<<Dbac<<"}"<<endl;
		cout<<"Teleword Scatter is  "<<telecount<<endl;
		cout<<"Heaviest Row:  "<<(a1+1)<<endl;
		cout<<"Heaviest Column:  "<<(b1+1)<<endl;
			}
			else
			{
				cout<<"Wrong Choice"<<endl;
			}
			
	}
	
	
		
			
	system("pause");
}
/* 
	#include <chrono>
	
						
*/