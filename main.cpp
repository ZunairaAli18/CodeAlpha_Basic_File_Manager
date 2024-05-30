#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;
//Read from the file
void Read(){
    string name;
    cout<<"Enter filename you want to open: "<<endl;
    cin>>name;
    string filename=name+".txt";
    ifstream is;
    is.open(filename,ios::in);
    if(!is){
        cout<<"There is no such file"<<endl;
    }
    else{
        string line;
        while(getline(is,line)){
            cout<<line<<endl;
        }
        is.close();
    }
}
//Write into the file
void Write(){
    string name;
    cout<<"Enter filename you want to open: "<<endl;
    cin>>name;
    string filename=name+".txt";
    ofstream os;
    os.open(filename,ios::out);
    if(!os){
        cout<<"File is not created!"<<endl;
    }
    else{
        string str;
        cout<<"Enter what you want to write in your file: "<<endl;
        cin.ignore();
        getline(cin,str);
        os<<str<<endl;
        os.close();
        cout<<"Data has been written to the file."<<endl;
    }
}
//Write in append mode
void WriteinAppendmode(){
    ofstream os;
    string name;
    cout<<"Enter filename you want to open: "<<endl;
    cin>>name;
    string filename=name+".txt";
    os.open(filename,ios::app);
    if(!os){
        cout<<"File is not created"<<endl;
    }
    else{
       string str;
       cout<<"Enter what you want to write in your file: "<<endl;
       cin.ignore();
       getline(cin,str);
       os<<str<<endl;
       os.close();
       cout<<"Data has been written to the file in append mode."<<endl;
    }
}
//Copy
void Copy(){
    string name;
    cout<<"Enter filename you want to copy"<<endl;
    cin>>name;
    string filename=name+".txt";
    ifstream is;
    ofstream os;
    is.open(filename,ios::in);
    os.open("tempfile.txt",ios::out);
    if(!is){
        cout<<"No such file exists"<<endl;
    }
    if(!os){
        cout<<"Error creating temporary file."<<endl;
    }
    else{
       string line;
       while(getline(is,line)){
        os<<line;
       }
       os.close();
       is.close();
       cout<<"File has been copied to a temp file"<<endl;
    }
}
//Delete
void DeletetheFile(){
    char* name;
    cout<<"Enter filename you want to delete"<<endl;
    cin>>name;
    strcat(name,".txt");
    if(remove(name)!=0){
       cout<<"Error deleting file"<<endl;
    }
    else{
        cout<<"File has been deleted successfully"<<endl;
    }
}
//Erase
void EraseDataFromTheFile(){
    string name;
    string tempfilename="tempfile.txt";
    cout<<"Enter filename you want to erase data from"<<endl;
    cin>>name;
    string filename=name+".txt";
    ifstream is;
    ofstream os;
    is.open(filename,ios::in);
    os.open(tempfilename,ios::out);
    if(!is){
        cout<<"No such file exists"<<endl;
    }
    if(!os){
        cout<<"Error creating temporary file."<<endl;
    }
    else{
        string data;
        cout<<"Enter data or a word from a line which you want to delete from the file"<<endl;
        cin>>data;
        string line;
        while(getline(is,line)){
           if(line.find(data) == string::npos){
            os<<line;
           }
           os.close();
           is.close();
           if(remove(filename.c_str()) != 0){
             cout<<"Error deleting original file"<<endl;
           } 
           else if(rename(tempfilename.c_str(), filename.c_str()) != 0)
           {
             cout << "Error renaming temporary file" << endl;
           } 
           else {
             cout << "Data erased from file" << endl;
           }
        }
    }  
}
//Update
void Update(){
    string name;
    string tempfilename="tempfile.txt";
    cout<<"Enter filename you want to update"<<endl;
    cin>>name;
    string filename=name+".txt";
    ifstream is;
    ofstream os;
    is.open(filename,ios::in);
    os.open(tempfilename,ios::out);
    if(!is){
        cout<<"No such file exists."<<endl;
    }
    if(!os){
        cout<<"Error creating temporary file."<<endl;
    }
    else{
        int n=0,count=0;
       cout<<"Enter line no you want to update"<<endl;
       cin>>n;
       string data;
       cout<<"Enter updated line"<<endl;
       cin.ignore();
       getline(cin,data);
       string line;
       string updateddata;
       while(getline(is,line)){
           count++;
           if(count == n){
            os<<data;
           }
           else{
            os<<line;
           }
       }
       //If the file is empty
       if(count==0){
        os<<data;
       }
       os.close();
       is.close();
       if(remove(filename.c_str()) != 0){
        cout<<"Error deleting origial file."<<endl;
       }
       else if(rename(tempfilename.c_str(),filename.c_str())!=0){
        cout<<"Error renaming file."<<endl;
       }
       else{
        cout<<"File has been updated successfully!"<<endl;
       }
    }
}
//Create
void Create(){
    ofstream os;
    cout<<"Enter file name for the new file you want to create: "<<endl;
    string name;
    cin>>name;
    string filename=name+".txt";
    os.open(filename,ios::out);
    if(!os){
        cout<<"Error creating file!!"<<endl;
    }
    else{
        cout<<"File has been successfully created!"<<endl;
        os.close();
    }
}
//Search in the file
void Search(){
    string name;
    cout<<"Enter filename you want to open: "<<endl;
    cin>>name;
    string filename=name+".txt";
    ifstream is;
    is.open(filename,ios::in);
    if(!is){
        cout<<"There is no such file"<<endl;
    }
    else{
        bool flag=false;
        string data;
        cout<<"Enter data you want to search in the file"<<endl;
        cin.ignore();
        getline(cin,data);
        string line;
        while(getline(is,line)){
            if(line.find(data)!= string::npos){
                cout<<line<<endl;
                flag=true;
            }
        }
        is.close();
        if(!flag){
            cout<<"No such data found"<<endl;
        }
    }
}
int main(){
    char choice;
    cout<<"Welcome to the Basic File Manager: "<<endl;
    do{
    cout<<"Choose option from here..."<<endl;
    cout<<"1: Create a new File"<<endl;
    cout<<"2: Read the file"<<endl;
    cout<<"3: Write in the file"<<endl;
    cout<<"4: Write in append mode"<<endl;
    cout<<"5: Copy the file"<<endl;
    cout<<"6: Search from the File"<<endl;
    cout<<"7: Update the file"<<endl;
    cout<<"8: Delete a file"<<endl;
    cout<<"9: Erase data from the file"<<endl;
    int ch=0;
    cin>>ch;
    switch(ch){
        case 1:
           Create();
           break;
        case 2:
           Read();
           break;
        case 3:
           Write();
           break;  
        case 4:
           WriteinAppendmode();
           break;
        case 5:
           Copy();
           break;
        case 6:
           Search();
           break;   
        case 7:
           Update();   
           break;
        case 8:
           DeletetheFile();
           break;
        case 9:
           EraseDataFromTheFile();
           break;
        default:
        cout<<"Invalid choice"<<endl;
        break;   
    }
    cout<<"Do you want to perform more tasks on file? (y/n)"<<endl;
    cin>>choice;
    }while(choice=='Y' || choice =='y');
    cout<<"ThankYou !!"<<endl;
    return 0;
}