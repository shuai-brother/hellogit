#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Student{
        string name,sex;
        double s;
}stu[10001];

bool cmp(Student A,Student B)
{
        if(A.s==B.s)return A.name<B.name;
        else return A.s>B.s;
}

int main()
{
        //ifstream fin("score.csv");
        freopen("score.csv","r",stdin);
        string s1,s2,nothing;
        double sc,sum=0,fsum=0,msum=0;
        int num=0,fnum=0,mnum=0;
        getline(cin,nothing);
        while(!cin.eof())
        {
		cin>>stu[++num].name;
		cin>>stu[num].sex>>stu[num].s;
                sum+=stu[num].s;
                if(stu[num].sex[0]=='F')fsum+=stu[num].s,fnum++;
                else msum+=stu[num].s,mnum++;
        }
	while(stu[num].name.length()==0)num--;
        sort(1+stu,1+stu+num,cmp);
        fsum/=fnum;msum/=mnum;sum/=num;
        cout<<fixed<<setprecision(1)<<"av score: "<<sum;
        cout<<endl<<"Female av score: "<<fsum;
        cout<<endl<<"Male av score: "<<msum<<endl;
        for(int i=1;i<=num;i++)
                cout<<stu[i].name<<stu[i].sex<<stu[i].s<<endl;
        return 0;
}

