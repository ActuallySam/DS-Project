#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
#include<windows.h>
#include<time.h>
//   declarations of functions
using namespace std;
int search(int);
int display();
string check(int);       //   for checking quantity
void loadingbar(void);
void backuploader(void);
void ccolor(int);
 //   build a node  
struct node {
int ID;
string proName;
double prePrice;            //   product price
int quantity;
struct    node* next;
};
struct node *head=NULL;
//      for entering(saving) 1st record in list
void ccolor(int clr){

HANDLE  hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, clr);

}
void cls(){

system("cls");

}
void backuploader(void){

for (int i=15;i<=100;i+=5){

cls();
ccolor(26);

printf("\n\n\n\n\n\n\n\t\t\t\t");
printf("%d %% Backing UP DATA...\n\n\t\t",i);

printf("");

for (int j=0; j<i;j+=2){

ccolor(120+j);
printf(" ");
ccolor(26);

}
Sleep(50);
if(i==90 || i==50 || i==96 || i==83){
Sleep(50);
}
}

}
void loadingbar(void){

for (int i=15;i<=100;i+=5){

cls();
ccolor(26);

printf("\n\n\n\n\n\n\n\t\t\t\t");
printf("%d %% Loading...\n\n\t\t",i);

printf("");

for (int j=0; j<i;j+=2){

ccolor(160+j);
printf(" ");
ccolor(26);

}
Sleep(100);
if(i==90 || i==50 || i==96 || i==83){
Sleep(100);
}

}

}
 void beg()      
{
system("cls");
int id,quant;           //  quant    for quantity
string name;
double pre;            //  pre for price
struct node *t=new node;
cout<<"\t\t\tEnter product ID:-";
cin>>id;
t->ID=id;
cout<<"\t\t\tEnter product Name:-";
cin>>name;
t->proName=name;
cout<<"\t\t\tEnter product price:-";
cin>>pre;
t->prePrice=pre;
cout<<"\t\t\tEnter product quantity:-";
cin>>quant;
t->quantity=quant;
t->next=head;
head=t;
system("cls");
cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";
}
// for entering(saving) 2nd and onward records in list
void end()
{
system("cls");
int id,quant;      //   quant for quantity
string name;
double pre;            //  pre for price
struct node *t=new node;
struct node *p=head;
cout<<"\t\t\tEnter product ID:-";
cin>>id;
t->ID=id;
cout<<"\t\t\tEnter product Name:-";
cin>>name;
t->proName=name;
cout<<"\t\t\tEnter product price:-";
cin>>pre;
t->prePrice=pre;
cout<<"\t\t\tEnter product quantity:-";
cin>>quant;
t->quantity=quant;
while(p->next!=NULL)
{
p=p->next;
}
p->next=t;
t->next=NULL;
system("cls");
cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";
}
void delPro()
{
system("cls");
display();
int id;
struct node *cur=head;
struct node *pre=head;
cout<<"\n\nEnter ID to delete that product:\n\n";
cin>>id;
if (head == NULL)
    {
    system("cls");
        cout<<"List is empty"<<endl;
    }
int pos=0;
int count=display();               //   for load no of nodes
pos=search(id);                        //   for check weather desire node is exist or not    
if(pos<=count){

while(cur->ID!=id){                //  for delete middle area products
pre=cur;
cur=cur->next;
}
pre->next=cur->next;
system("cls");
cout<<"\n<<item is deleted>>\n";
}else{
cout<<"\n<<<Not found>>\n\n";
}
}
void modify(){
int id;
double pre;        //    pre for price
string pName;      //   pName for new name
if (head == NULL)
    {
    system("cls");
        cout<<"List is empty"<<endl;
    }else
{
cout<<"\n\nEnter ID to modify product Name and its price:\n";
cin>>id;
struct node *cur=head;
int pos=0;
int count=display();               //   for load no of nodes
pos=search(id);                        //   for check weather desire node is exist or not    
if(pos<=count){

while(cur->ID!=id){
cur=cur->next;
}
cout<<"\nOld Name : "<<cur->proName;
cout<<"\nOld Sallary : "<<cur->prePrice<<endl;
cout<<"Enter new Name:";
cin>>pName;
cur->proName=pName;
cout<<"Enter new Price:";
cin>>pre;
cur->prePrice=pre;
}else{
cout<<id<<" is <<<Not found>>\n\n";
}
}
}
void saveOnFile()
{
system("cls");

  ofstream myfile ("Products Record.txt");
 
  if (myfile.is_open())
  {
    myfile << "ID \t\t Product Name \t\t\t\t\t Price \t\t\t Quantity \n";
    struct node *p=head;
    int c=0;          //   c for count products
while(p!=NULL)
{
myfile<<p->ID<<"\t\t"<<p->proName<<"\t\t\t\t"<<p->prePrice<<"\t\t\t"<<check(p->quantity)<<"\n";
p=p->next;
c=c+1;
}
myfile<<"\nTotal products in our store is : "<<c;
}
    myfile.close();
    system("cls");
    cout<<"\n\n\t\t\tFile saved!\n";
}

int display(){
system("cls");
int c=0;             //   c for count products
struct node *p=head;
cout<<"Existing products are:\n";
cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
while(p!=NULL)
{
cout<<p->ID<<"\t\t"<<p->proName<<"\t\t\t\t"<<p->prePrice<<"\t\t"<<check(p->quantity)<<"\n"; //    call   check func and pass quantity
p=p->next;
c=c+1;
}
cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
return c;
}

   string check(int quant){              //        check function  
   int a = quant;
       stringstream ss;
       ss << a;
       string quantity = ss.str();
       
    if(quant<=0)
    return "out of stock!";
    else
    return quantity;
}
   
void OldProducts(){
  system("cls");
  string line;
        ifstream myfile ("Products Record.txt");
        if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    cout<<"\n\n";
    myfile.close();
  }
  else cout << "Unable to open file\n\n";
}

void buy(){
system("cls");
string products[20]; //   for display sold items
int pay=0,no,c=0,price,id,i=1;
if(head==NULL) {
cout<<"\n<<<<There is no items to buy>>>>\n\n";
}
else{
cout<<"How many items you wanna to buy!\n";
cin>>no;
int count=display();           //   for store no of nodes  in c
while (i<=no){
struct node *cur=head;

int quant,cho;              //   quant   for quantity  and cho for choice
cout<<"Enter id of item that you want to buy: ";
int id,pos=0;
cin>>id;
pos=search(id);
if(pos<=count){  
                       //     item is available in store
while(cur->ID!=id){
cur=cur->next;
}
       
cout<<"How many quantities you want:";
cin>>quant;
products[c]=cur->proName; c++;
pay=pay+(cur->prePrice*quant);         //     calculate Bill
cur->quantity=cur->quantity-quant;           //    change quantity
i++;
}
else{
cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
   }
}

system("cls");
cout<<"\n\n\n\n\t\t\tYou have bought : ";
for(int i=0;i<no;i++){              //    show that item you have bought
cout<<products[i]<<",";
}
price=pay*(0.95);           //    with 5% discount
cout<<"\n\nOriginal price : "<<pay;
    cout<<"\n with 5% discount: "<<price<<"\nThank you! for the shopping\n\n";
}
}

int search(int id)                     //    for search item in list
 {
  int count=1;
  struct node *p=head;
  while(p!=NULL)
  {
  if(p->ID==id)
  break;              
  else
  count++;
  p=p->next;
}
  return count;
 }
                       //        Main function
int main(){
    system("title ..................DS PROJECT PRESENTANTION.......................");
system("mode con: cols=80 lines=30");


loadingbar(); cls();
system("color 1A");     //  for console color
cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<   SuperMarket   >>>>>>>>>>>>>>>>>>>>\n";              //  \xB2  is for styling
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<   Store         >>>>>>>>>>>>>>>>>>>>\n";
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<   System        >>>>>>>>>>>>>>>>>>>>\n\n \t\t\t\t\t\t";  // message
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";              //  on console

int temp=1;
while(true){
int ch;                     //            choice for below message
cout<<"\t\tEnter 1 for ADD a new product \n\n\t\tEnter 2 to display all products \n\n\t\tEnter 3 for MODIFY Existing product\n\n";
cout<<"\t\tEnter 4 for Delete a particular product item\n\n\t\tEnter 5 for Buy something\n\n\t\tEnter 0 for exit\n\n";
cout<<"*********>>>>>***********>>>>>>>>";   cin>>ch;    
switch(ch){
case 1:
if (temp==0){              //    Second time and on ward this is only executed
end();
}
if(temp==1){               //    this will be executed only one time
beg();
temp=0;
}
break;
case 2:
system("cls");
cout<<"1>> for show old products that are saved in file\n";
    cout<<"2>> for save current products on file\n";
    cout<<"3>> for Show Existing Items\n";
    int c; cin>>c;
    if(c==1) OldProducts();
    if(c==2) saveOnFile();
    if(c==3) display();
    break;
case 3:
modify();
break;
case 4:
delPro();
break;
case 5:
buy();
break;
case 0:
        cout<<"Exiting..."<<end;
   exit(true);                    //   exit from while loop
        break;
default: system("cls");
         cout<<"\t\t<<<Wrong choice>>>\n\n";
}
}
}

