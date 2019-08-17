#include"common.h"
#include"dataManger.h"
class Scan{
public:
	Scan(const string path) :
		_path(path)
	{

		//std::thread thr(&Scan::doit,this,a,_path);
		//thr.detach();
		//doit(a, _path);
	}

	void doit(DataManager* a, const std::string path){

		//while (1){
			a->ExecuteSql("BEGIN");
			Scan::scanall(a, path);
			a->ExecuteSql("COMMIT");
			cout << "ok" << endl;
		//	Sleep(2);
	//	}
		
		//listendir(path);
		

	}

	static void scanall(DataManager* a, const std::string path ){
		
		vector<string> localdoc;
		vector<string> localdir;
		DirectoryList(path, localdoc, localdir);
		std::set<std::string> local;
		for (int i = 0; i < localdoc.size(); i++){
			local.insert(localdoc[i]);
		}
		for (int i = 0; i < localdir.size(); i++){
			local.insert(localdir[i]);
			//string hpath = path + "\\" + localdir[i];
			/*HANDLE dwChangeHandles = FindFirstChangeNotification(hpath.c_str(), FALSE,  FILE_NOTIFY_CHANGE_DIR_NAME |   FILE_NOTIFY_CHANGE_SIZE |       FILE_NOTIFY_CHANGE_ATTRIBUTES);
			
			listenit.insert(std::make_pair(dwChangeHandles, path));
			_xlistenit.push_back(dwChangeHandles);*/
		}
		std::set<std::string> sqldocs;
		//a->GetDocs(path, sqldocs);
		std::set<std::string>::iterator loc_it = local.begin();
		std::set<std::string>::iterator sql_it = sqldocs.begin();
		while (loc_it != local.end() && sql_it != sqldocs.end()){
			if ((*loc_it) < (*sql_it)){
				a->InsertDoc(path, *loc_it);
				loc_it++;
				continue;
			}
			if ((*loc_it) > (*sql_it)){
				a->DeleteDoc(path, *sql_it);
				string dirpath = path + "\\";
				a->DeleteDir(dirpath);
				sql_it++;
				continue;
			}
			if ((*loc_it) == (*sql_it)){
				loc_it++;
				sql_it++;
				continue;
			}

		}
		while (loc_it != local.end()){
			a->InsertDoc(path, *loc_it);
			loc_it++;
			
		}
		while (sql_it != sqldocs.end()){
			a->DeleteDoc(path, *sql_it);
			string dirpath = path + "\\";
			a->DeleteDir(dirpath);
			sql_it++;
		}
		for (int i = 0; i <localdir.size(); i++){
			if (path.find(localdir[i]) < path.size()){
				continue;
			}
			string newpath = path + "\\" + localdir[i];
			scanall(a, newpath);
		}
	}

	//static void scanlite(DataManager* a, const std::string path){

	//	vector<string> localdoc;
	//	vector<string> localdir;
	//	DirectoryList(path, localdoc, localdir);
	//	std::set<std::string> local;
	//	for (int i = 0; i < localdoc.size(); i++){
	//		local.insert(localdoc[i]);
	//	}
	//	for (int i = 0; i < localdir.size(); i++){
	//		local.insert(localdir[i]);

	//	}



	//	std::set<std::string> sqldocs;
	//	a->GetDocs(path, sqldocs);
	//	std::set<std::string>::iterator loc_it = local.begin();
	//	std::set<std::string>::iterator sql_it = sqldocs.begin();
	//	while (loc_it != local.end() && sql_it != sqldocs.end()){
	//		if ((*loc_it) < (*sql_it)){
	//			a->InsertDoc(path, *loc_it);
	//			loc_it++;
	//			continue;
	//		}
	//		if ((*loc_it) > (*sql_it)){
	//			a->DeleteDoc(path, *sql_it);
	//			string dirpath = path + "\\";
	//			a->DeleteDir(dirpath);
	//			sql_it++;
	//			continue;
	//		}
	//		if ((*loc_it) == (*sql_it)){
	//			loc_it++;
	//			sql_it++;
	//			continue;
	//		}
	//	}
	//	while (loc_it != local.end()){
	//		a->InsertDoc(path, *loc_it);
	//		loc_it++;
	//	}
	//	while (sql_it != sqldocs.end()){
	//		a->DeleteDoc(path, *sql_it);
	//		string dirpath = path + "\\";
	//		a->DeleteDir(dirpath);
	//		sql_it++;
	//	}
	//	for (int i = 0; i < localdir.size(); i++){
	//		string newpath = path + "\\" + localdir[i];
	//		scanlite(a, newpath);
	//	}
	//}

	void search(const string &name, vector<std::pair<std::string, std::string>>&doc_paths){
		a->Search(name, doc_paths);
	}
	void  listendir(string path)
	{
		HANDLE dwChangeHandles[1000] = { 0 };
		for (int i = 0; i < _listenit.size(); i++){
			dwChangeHandles[i] = _xlistenit[i];
		}

		while (1){

			for (int i = 3; i < _listenit.size(); i++){
			_dwWaitStatus = WaitForSingleObject(dwChangeHandles[i], INFINITE);
			if (_dwWaitStatus == 0){
				cout << "文件更新改动" << endl;
				break;
			}
			}
			/*if (_dwWaitStatus < 1000){
				string genxin = _listenit[_xlistenit[_dwWaitStatus]];
				scanlite(a, genxin);
				cout << "文件更新改动" << endl;*/
			//}
		}
	}







	~Scan()
	{

	}


	
private:
	DataManager* a= DataManager::GetInstance();
	std::map < HANDLE, string  > _listenit;
	std::vector<HANDLE>_xlistenit;
	const std::string _path;
	DWORD _dwWaitStatus;
	



};