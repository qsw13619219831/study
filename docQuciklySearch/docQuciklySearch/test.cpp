#include"common.h"
#include"ScanManger.h"




int main(){
	
	cout << "=============================================================================================================" << endl;
	cout << "������Ҫ���ҵ��ļ��Ĺؼ���" << endl;
	Scan all("C:\\");
	std::string search;
	while (cin >> search){
		search = ChineseConvertPinYinAllSpell(search);
	vector<std::pair<std::string, std::string>>doc_paths;
	all.search(search, doc_paths);
	for (int i = 0; i < doc_paths.size(); i++){
		Highlight(doc_paths[i], search);

	}
	cout << "==============================================================================================================" << endl;
	cout << "������Ҫ���ҵ��ļ��Ĺؼ���" << endl;
	}
	system("pause");
}