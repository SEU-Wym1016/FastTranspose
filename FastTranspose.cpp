// FastTranspose.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <vector>
using namespace std;
struct Triple{
	int i,j,value;
	Triple(int a=0,int b=0,int c=0):i(a),j(b),value(c){
	}
};
class SMatrix{
public:
	void setRow(int a){
		row=a;
	}
	void setColumn(int b){
		column=b;
	}
	void setTerms(int c){
		terms=c;
	}
	void setData(vector<Triple> d){
		data=d;
	}
	SMatrix(vector<Triple> d=vector<Triple>(),int a=0,int b=0,int c=0):row(a),column(b),terms(c),data(d){
	}
	void printMatrix(){
		vector<vector<int>> matrix(row,vector<int>(column,0));
		for(int k=0;k<terms;k++){
			int m=data[k].i;
			int n=data[k].j;
			matrix[m][n]=data[k].value;
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void input(){
		cout<<"请输入行数"<<endl;
		cin>>row;
		cout<<"请输入列数"<<endl;
		cin>>column;
		cout<<"请输入矩阵元素"<<endl;
		int temp=0;
		data.clear();terms = 0;
		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++){
				cin>>temp;
				if(temp!=0){
					Triple tmp;
					terms++;
					tmp.i=i;
					tmp.j=j;
					tmp.value=temp;
					data.push_back(tmp);
				}
			}
		}
	}
	SMatrix transpose(){
		SMatrix newMatrix;
		newMatrix.row=column;
		newMatrix.column=row;
		newMatrix.terms=terms;
		vector<Triple> newTriple(terms);
		vector<int> originalColumnCount(column,0);
		for(int i=0;i<terms;i++){
			originalColumnCount[data[i].j]++;
		}
		vector<int> start(column,0);
		for(int i=0;i<column;i++){
			if(i==0)
				start[i]=0;
			else
				start[i]=originalColumnCount[i-1]+start[i-1];
		}
		int index=0;
		for(int i=0;i<terms;i++){
			index=start[data[i].j];
			newTriple[index].i=data[i].j;
			newTriple[index].j=data[i].i;
			newTriple[index].value=data[i].value;
			start[data[i].j]++;
		}
		newMatrix.data=newTriple;
		return newMatrix;
	}
private:
	int row,column;
	int terms;
	vector<Triple> data;
};
int main()
{
	//vector<Triple> d;
    //d.push_back(Triple(0,2,5));
    //d.push_back(Triple(1,0,9));
    //d.push_back(Triple(1,3,7));
    //d.push_back(Triple(2,1,6));
    //d.push_back(Triple(3,3,12));
	//SMatrix test(d,4,4,5);
	//SMatrix test1=test.transpose();
	//test1.printMatrix();
	SMatrix test2;
	test2.input();
	test2.transpose().printMatrix();
	system("pause");
	return 0;
}

