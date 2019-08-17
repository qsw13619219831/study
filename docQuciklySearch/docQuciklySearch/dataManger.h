#include"common.h"

class SQLliteManger{
public:
	SQLliteManger()
		:_dbfd(nullptr)
	{
	}
	
	~SQLliteManger(){
		
		Close();
	}


	void init();
	void Close();
	void ExecuteSql( const char*ss);
	void GetTable( const char*sql, int& row, int& col, char**& ppRet);

private:	
	sqlite3* _dbfd;
	int _count = 0;
};



class Erromsg
{
public:
	Erromsg():
		_emsg(NULL)
	{}
	~Erromsg(){
		sqlite3_free(_emsg);
	}


private:
	Erromsg(const Erromsg&) = delete;
	Erromsg& operator=(const Erromsg&) = delete;
public:
	char*_emsg;
};


class AutoGetTable
{
public:
	AutoGetTable(SQLliteManger& dbObject, const char* sql, int& row, int& col, char**& ppRet, std::set<std::string>& docs)
		: _ppObject(0)
	{
		dbObject.GetTable(sql, row, col, ppRet);
		_ppObject = ppRet;

		for (int i = col; i <= row*col; i++){
			if (row*col == 0)
				break;
			string tem(ppRet[i]);
			docs.insert(tem);
		}
	}

	char**getit()const
	{
		return _ppObject;
	}
	virtual ~AutoGetTable()
	{
		if (_ppObject)
			sqlite3_free_table(_ppObject);
	}
private:
	AutoGetTable(const AutoGetTable&) = delete;
	AutoGetTable& operator=(const AutoGetTable&) = delete;
private:
	char** _ppObject;
};


class DataManager
{
public:
	~DataManager()
	{
		_dbmgr.Close();
	}
	static DataManager* DataManager::GetInstance()
	{
		static DataManager inst;
			return &inst;
	}
	void GetDocs(const std::string path, std::set<std::string>& docs);
	void InsertDoc(const std::string path, std::string doc);
	void DeleteDoc(const std::string path, std::string doc);
	void DeleteDir(const std::string path);
	void Search(const std::string& key, std::vector<std::pair<std::string, std::string>>&doc_paths);
	void ExecuteSql(const char*ss);
private:
	DataManager()
	{
		// 打开数据库
		_dbmgr.init();
		char sq[1024] = { 0 };
		sprintf(sq, "CREATE TABLE '%s'(ID integer PRIMARY KEY AUTOINCREMENT,doc char(50),path char(100),	pinying	  char(50),zimu		    char(50));", DB_TNAME);
		_dbmgr.ExecuteSql(sq);

	}
	DataManager(const DataManager&) = delete;
	SQLliteManger _dbmgr;
	int _count = 0;
};

