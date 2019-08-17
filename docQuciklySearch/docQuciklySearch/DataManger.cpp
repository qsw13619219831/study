#include"dataManger.h"


void SQLliteManger::init(){
	int ret = sqlite3_open(DB_NAME, &_dbfd);
	if (ret != SQLITE_OK){
		TRACE_LOG("SQL OPEN ");
	}
	else{
		TRACE_LOG("SQL OPEN SUCCESS");
	}
}
void SQLliteManger::Close(){
	int ret= sqlite3_close(_dbfd);
	if (ret != SQLITE_OK){
		TRACE_LOG("SQL CLOSE ");
	}
}


void SQLliteManger::ExecuteSql( const char* ss){
	_count++;
	if (_count == 5000){
		sqlite3_exec(_dbfd, "commit", NULL, NULL, NULL);
		_count = 0;
		sqlite3_exec(_dbfd, "begin", NULL, NULL, NULL);
		cout << "yici" << endl;
	}
	Erromsg msg;
	int ret = sqlite3_exec(_dbfd, ss, NULL, NULL, &msg._emsg);
	TRACE_LOG("sql dude erro %s", msg._emsg);

}


void SQLliteManger::GetTable( const char* sql, int& row, int& col, char**& ppRet){
	Erromsg getmsg;
	int ret= sqlite3_get_table(_dbfd,sql,&ppRet,&row,&col,&getmsg._emsg);
	TRACE_LOG("sql dude erro%s", getmsg._emsg);
	
}


void DataManager::GetDocs(const std::string path, std::set<std::string>& docs){
	char sq[1024] = { 0 };
	sprintf(sq, "SELECT doc FROM '%s' WHERE path = \'",DB_TNAME );
	string add = sq;
	string sqs = sq + path + '\'' + ';';
	int row = 0;
	int col = 0;
	char**ppret;
	AutoGetTable At(_dbmgr, sqs.c_str(), row, col, ppret,docs);
	
}


void DataManager::InsertDoc(const std::string path, std::string doc){
	char sq[1024] = { 0 };
	string pinyin=ChineseConvertPinYinAllSpell(doc);
	string shouzimu = "ss";
	sprintf(sq, "INSERT INTO '%s' (doc,path,pinying,zimu)VALUES('%s','%s','%s','%s');", DB_TNAME, doc.c_str(), path.c_str(), pinyin.c_str(), shouzimu.c_str());
	_dbmgr.ExecuteSql(sq);
}
void DataManager::DeleteDoc(const std::string path, std::string doc){
	char sq[1024] = { 0 };
	sprintf(sq, " DELETE FROM '%s' WHERE path = '%s'AND doc = '%s';", DB_TNAME, path.c_str(), doc.c_str());
	_dbmgr.ExecuteSql(sq);

}

void DataManager::DeleteDir(const std::string path){
	char sq[1024] = { 0 };
	sprintf(sq, " DELETE FROM '%s' WHERE path like '%s%s';", DB_TNAME, path.c_str(), "%");
	_dbmgr.ExecuteSql(sq);

}

void DataManager::Search(const std::string& key, std::vector<std::pair<std::string, std::string>>&doc_paths){
	char sq[1024] = { 0 };
	sprintf(sq, "SELECT doc, path FROM '%s' WHERE pinying like '%s%s%s';",DB_TNAME,"%",key.c_str(),"%" );
	int row = 0;
	int col = 0;
	char**ppret;
	std::set<std::string> docs;
	AutoGetTable at(_dbmgr, sq, row, col, ppret,docs);
	for (int i = col; i <= row*col; i += 2){
		if (row*col == 0)
			break;
		string tem = ppret[i];
		string tem1 = ppret[i + 1];
		doc_paths.push_back(std::make_pair(tem, tem1));
	}

}
void DataManager::ExecuteSql(const char*ss){ 
	_dbmgr.ExecuteSql(ss);
}