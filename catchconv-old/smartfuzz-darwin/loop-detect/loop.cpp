#include <map>
#include <list>
#include <string>
#include <fstream>
using namespace std;
inline unsigned int stoui(const string &str, ofstream &ferr)
{
	unsigned int result=0,index=0;
	while (index<str.length()&&(str[index]<'0'||str[index]>'9')) ++index;
	if (index==str.length())
	{
		ferr<<"Invalid String: "<<str<<endl;
		return 0;
	}
	do {
		result*=10;
		result+=str[index++]-'0';
	} while (index<str.length()&&str[index]>='0'&&str[index]<='9');
	return result;
}
int main(int argc, char *argv[])
{
	ofstream ferr("loop.err",ios::app);
	if (argc!=6) 
	{
		ferr<<"Argument Count Dismatch: "<<argc<<endl;
		ferr.close();
		return -1;
	}
	unsigned int threshold=stoui(argv[3],ferr);
        if (threshold==0) 
	{
		ferr<<"Loop Threshold = 0\n";
		ferr.close();
		return -1;
	}
	unsigned int first=stoui(argv[4],ferr);
	unsigned int last=stoui(argv[5],ferr);
	if (first==0&&last==0)
        {
		ferr<<"Loop KEEPS = 0\n";
                ferr.close();
                return -1;
        }
	ifstream fin(argv[1]);
	if (!fin.good())
	{
		ferr<<"File Open Fail:"<<argv[1]<<endl;
		fin.close();
		ferr.close();
		return -1;
	}
	map<string, list<list<string> > > hash;
	map<string, pair<unsigned int, unsigned char> > backjump;
	string key,query,line,path;
	unsigned int bb=0,nbb,index,nindex;
	while (getline(fin,line))
        {
		if (line[10]=='J')
		{
			for (index=23;line[index]!=' ';++index);
			query=line.substr(10,index-10);
			path.push_back('1');
		}
		else
		{
			for (index=28;line[index]!=' ';++index);
                        query=line.substr(11,index-11);
			path.push_back('0');
		}
		nbb=stoui(query,ferr);
		if (nbb<=bb) 
		{
			if (backjump.find(key)==backjump.end())
			{
				backjump[key].first=1;
				backjump[key].second=query[0];
			}
			else if (backjump[key].second==query[0]) ++backjump[key].first;
			else backjump[key].second=0;
		}
		bb=nbb;
		for (index+=3;line[index]!='X';++index);
		index+=19;
		for (nindex=index;line[nindex]!=' ';++nindex);
		key=line.substr(index,nindex-index);
                if (hash[key].empty()) hash[key].push_back(list<string>());
                hash[key].back().push_back(query);
        }
        fin.close();
	ofstream fpath("loop.path");
	fpath<<path;
	fpath.close();
	if (first+last>threshold) threshold=first+last;
	map<string, list<list<string> > >::iterator iter;
	unsigned char end;
	for (iter=hash.begin();iter!=hash.end();++iter)
	{
		end=backjump[iter->first].second;
		if (backjump[iter->first].first>=threshold&&end&&end!=iter->second.back().back()[0])
		{
			bb=0;
                	for (end=iter->second.back().back()[0];!iter->second.back().empty();iter->second.back().pop_back())
	                {
	                        if (iter->second.back().back()[0]==end)
	                        {
	                                if (iter->second.front().size()>=threshold) ++bb;
	                                iter->second.push_front(list<string>());
	                        }
	                        iter->second.front().push_front(iter->second.back().back());
	                }
			if (iter->second.front().size()>=threshold) ++bb;
	                iter->second.pop_back();
	                if (bb==1) backjump[iter->first].first=0;
		}
		else backjump[iter->first].first=0;
	}
	bb=first+last;
	nbb=0;
	list<list<string> >::iterator ii;
	list<string>::iterator iii;
	ofstream fout(argv[2]);
	for (iter=hash.begin();iter!=hash.end();++iter)
		if (backjump[iter->first].first>=threshold)
		{
			fout<<iter->first<<" "<<iter->second.size()<<endl;
			for (index=1,ii=iter->second.begin();ii!=iter->second.end();++ii,++index)
			{
				fout<<index<<" "<<(ii->size()<bb?ii->size():bb)<<endl;
				for (nindex=0,iii=ii->begin();iii!=ii->end();++iii,++nindex)
					if (nindex<first||ii->size()-nindex<=last) fout<<*iii<<endl;
					else ++nbb;
				fout<<endl;
			}
			fout<<endl;
		}
	fout.close();
	backjump.clear();
	hash.clear();
	ferr<<nbb<<endl<<endl;
	ferr.close();
	return 0;
}
