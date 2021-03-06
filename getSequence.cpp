
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "EyeMovementTypeTime.h"
using namespace std;
/*
名称:my_split(const std::string& src, const char& delim,
		 std::vector<std::string>& vec)
功能:用分隔符将源字符串分隔为多个子串并传出; n个分隔符, 分n+1个子串

参数:
	 src-传入参数, 源字符串;
	 delim-传入参数, 分隔符;
	 vec-传出参数, 子串的集合;

返回值:
	0-成功;
	其它-失败;
 */

struct point
{
	int x;
	int y;
	point(int a,int b) {
		x = a;
		y = b;
	}
};
point diagram_LU(823, 208);
point diagram_RB(1095, 314);

point optionA_LU(871, 537);
point optionA_RB(1037, 616);

point optionB_LU(871, 624);
point optionB_RB(1037, 689);

point optionC_LU(871, 702);
point optionC_RB(1037, 771);

point optionD_LU(871, 783);
point optionD_RB(1037, 852);

point option_LU(871, 537);
point option_RB(1037, 852);

point stament1_LU(414, 321);
point stament1_RB(990, 396);

point stament2_LU(990, 323);
point stament2_RB(1304, 405);

point stament_LU(414, 321);
point stament_RB(1304, 405);

point time_LU(1306, 306);
point time_RB(1471, 411);

vector<string> AOIs{
	"Diagram","OptionA","OptionB","OptionC","OptionD","Statement1","Statement2","Time","Else"
};

vector<string> AOIs2{
	"Diagram","OptionA","OptionB","OptionC","OptionD","Statement","Time","Else"
};

vector<string> AOIs3{
	"Diagram","Option","Statement","Time","Else"
};
int inWhichAOI(int x,int y) {
	if (x >= diagram_LU.x&&x <= diagram_RB.x &&y >= diagram_LU.y&&y <= diagram_RB.y) {
		return 0;
	}
	else if (x >= optionA_LU.x&&x <= optionA_RB.x &&y >= optionA_LU.y&&y <= optionA_RB.y) {
		return 1;
	}
	else if (x >= optionB_LU.x&&x <= optionB_RB.x &&y >= optionB_LU.y&&y <= optionB_RB.y) {
		return 2;
	}
	else if (x >= optionC_LU.x&&x <= optionC_RB.x &&y >= optionC_LU.y&&y <= optionC_RB.y) {
		return 3;
	}
	else if (x >= optionD_LU.x&&x <= optionD_RB.x &&y >= optionD_LU.y&&y <= optionD_RB.y) {
		return 4;
	}
	else if (x >= stament1_LU.x&&x <= stament1_RB.x &&y >= stament1_LU.y&&y <= stament1_RB.y) {
		return 5;
	}
	else if (x >= stament2_LU.x&&x <= stament2_RB.x &&y >= stament2_LU.y&&y <= stament2_RB.y) {
		return 6;
	}
	else if (x >= time_LU.x&&x <= time_RB.x &&y >= time_LU.y&&y <= time_RB.y) {
		return 7;
	}
	else {
		return 8;
	}
}
int inWhichAOI2(int x, int y) {//Statement合并
	if (x >= diagram_LU.x&&x <= diagram_RB.x &&y >= diagram_LU.y&&y <= diagram_RB.y) {
		return 0;
	}
	else if (x >= optionA_LU.x&&x <= optionA_RB.x &&y >= optionA_LU.y&&y <= optionA_RB.y) {
		return 1;
	}
	else if (x >= optionB_LU.x&&x <= optionB_RB.x &&y >= optionB_LU.y&&y <= optionB_RB.y) {
		return 2;
	}
	else if (x >= optionC_LU.x&&x <= optionC_RB.x &&y >= optionC_LU.y&&y <= optionC_RB.y) {
		return 3;
	}
	else if (x >= optionD_LU.x&&x <= optionD_RB.x &&y >= optionD_LU.y&&y <= optionD_RB.y) {
		return 4;
	}
	else if (x >= stament_LU.x&&x <= stament_RB.x &&y >= stament_LU.y&&y <= stament_RB.y) {
		return 5;
	}
	else if (x >= time_LU.x&&x <= time_RB.x &&y >= time_LU.y&&y <= time_RB.y) {
		return 6;
	}
	else {
		return 7;
	}
}
int inWhichAOI3(int x, int y) {//Statement合并
	if (x >= diagram_LU.x&&x <= diagram_RB.x &&y >= diagram_LU.y&&y <= diagram_RB.y) {
		return 0;
	}
	else if (x >= option_LU.x&&x <= option_RB.x &&y >= option_LU.y&&y <= option_RB.y) {
		return 1;
	}
	else if (x >= stament_LU.x&&x <= stament_RB.x &&y >= stament_LU.y&&y <= stament_RB.y) {
		return 2;
	}
	else if (x >= time_LU.x&&x <= time_RB.x &&y >= time_LU.y&&y <= time_RB.y) {
		return 3;
	}
	else {
		return 4;
	}
}
int my_split(const string& src, const char& delim,
	vector<string>& vec)
{
	int src_len = src.length();
	int find_cursor = 0;
	int read_cursor = 0;

	if (src_len <= 0) return -1;

	vec.clear();
	while (read_cursor < src_len) {

		find_cursor = src.find(delim, find_cursor);

		//1.找不到分隔符
		if (-1 == find_cursor) {
			if (read_cursor <= 0) return -1;

			//最后一个子串, src结尾没有分隔符
			if (read_cursor < src_len) {
				vec.push_back(src.substr(read_cursor, src_len - read_cursor));
				return 0;
			}
		}
		//2.有连续分隔符的情况
		else if (find_cursor == read_cursor) {
			//字符串开头为分隔符, 也按空子串处理, 如不需要可加上判断&&(read_cursor!=0)
			vec.push_back(string(""));
		}
		//3.找到分隔符
		else
			vec.push_back(src.substr(read_cursor, find_cursor - read_cursor));

		read_cursor = ++find_cursor;
		if (read_cursor == src_len) {
			//字符串以分隔符结尾, 如不需要末尾空子串, 直接return
			vec.push_back(string(""));
			return 0;
		}
	}//end while()
	return 0;
}

int main()
{
/*
	//Sequence1
	FILE *fp;
	const string in_dir = "E:\\read\\";
	const string out_dir = "E:\\out";
	const string out_path = out_dir + "\\Sequence1.txt";
	ofstream out_file(out_path, ofstream::out);
	out_file << "Fixation+Saccade+Unclassified, Raw, total sequence XX" << endl;
	string line = "Recording,Sequence";
	//out_file << line << endl;
	//vector<string> names{
	//	"Project77-70 Recording18","Project77-70 Recording26",
	//	"Project77-70 Recording46","Project77-70 Recording70",
	//	"Project63-57 Recording24","Project63-57 Recording28",
	//	"Project63-57 Recording30",
	//	"Project77_56-49 Recording20"
	//};
	vector<string> names{
	"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
	"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
	"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
	"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
	"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
	"Project77_56-49 Recording35","Project77_56-49 Recording38"
	};

	//vector<string> names{
	//"Project77-70 Recording70"
	//};

	string in_path;
	for (int k = 0; k < names.size(); k++) {
		in_path = in_dir + names[k] + ".tsv";
		cout << "第" << k << "个文件路径为：" << in_path << endl;
		fp = fopen(in_path.c_str(), "r");//string to const char*
		if (!fp)
		{
			cout << "OPEN ERROR!" << endl;
			return 0;
		}
		int i = 0;
		EyeMovementTypeTime eyeMovementTypeTime;//8 AOIs
		vector<string> sequence;

		char original_data[1000], data2[1000];
		fgets(original_data, sizeof(original_data), fp);
		const char * split = "\t";
		string last_eye_movement_type = "0";
		int start_flag = 0; 
		stringstream ss;
		vector <string> res;//用于记录总数
		out_file << names[k] << "," << endl;
		while (original_data != "")
		{
			i++;//recode current line
			vector<string> line;
			fgets(original_data, sizeof(original_data), fp);//get a line data in .tsv
			my_split(original_data, '\t', line);
			if (line.size() == 0) {
				break;
			}
			if (line[11] != last_eye_movement_type) {//line11 Eye movement type
				//eyeMovementTypeTime.addTime(line[11], stoi(line[12]));
				if (line[11] == "Fixation") {
					//if (line[14] != ""&&line[15] != "") {//line 14,15 Fixation point X,Fixation point Y
						int index = inWhichAOI(atoi(line[14].c_str()), atoi(line[15].c_str()));
						ss << AOIs[index] << "," << line[12]<< "->";//line 12 Gaze event duration
						string temp = AOIs[index] + "," + line[12] + "->";
						res.push_back(temp);
					//}
				}
				else if (line[11] == "Saccade") {
					ss << "Saccade" << "," << line[12] << "->";//line 12 Gaze event duration
					string temp = "Saccade," + line[12] + "->";
					res.push_back(temp);
				}
				else if (line[11] == "Unclassified") {
					ss << "Unclassified" << "," << line[12] << "->";//line 12 Gaze event duration
					string temp = "Unclassified," + line[12] + "->";
					res.push_back(temp);
				}
			}
			last_eye_movement_type = line[11];

			if (feof(fp))
				break;
		}
		ss << endl;
		ss << "total sequence " << res.size() << endl;
		
		cout << ss.str() << endl;
		out_file << ss.str() << endl;

		fclose(fp);
	}
	out_file.close();
	system("pause");
*/

/*
	//Sequence2
	FILE *fp;
	const string in_dir = "E:\\read\\";
	const string out_dir = "E:\\out";
	const string out_path = out_dir + "\\Sequence2.txt";
	ofstream out_file(out_path, ofstream::out);
	out_file << "Fixation+Saccade, Raw, total sequence XX" << endl;
	string line = "Recording,Sequence";
	//out_file << line << endl;
	//vector<string> names{
	//	"Project77-70 Recording18","Project77-70 Recording26",
	//	"Project77-70 Recording46","Project77-70 Recording70",
	//	"Project63-57 Recording24","Project63-57 Recording28",
	//	"Project63-57 Recording30",
	//	"Project77_56-49 Recording20"
	//};
	vector<string> names{
	"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
	"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
	"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
	"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
	"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
	"Project77_56-49 Recording35","Project77_56-49 Recording38"
	};

	//vector<string> names{
	//"Project77-70 Recording70"
	//};

	string in_path;
	for (int k = 0; k < names.size(); k++) {
		in_path = in_dir + names[k] + ".tsv";
		cout << "第" << k << "个文件路径为：" << in_path << endl;
		fp = fopen(in_path.c_str(), "r");//string to const char*
		if (!fp)
		{
			cout << "OPEN ERROR!" << endl;
			return 0;
		}
		int i = 0;
		EyeMovementTypeTime eyeMovementTypeTime;//8 AOIs
		vector<string> sequence;

		char original_data[1000], data2[1000];
		fgets(original_data, sizeof(original_data), fp);
		const char * split = "\t";
		string last_eye_movement_type = "0";
		int start_flag = 0;
		stringstream ss;
		vector <string> res;//用于记录总数
		out_file << names[k] << "," << endl;
		while (original_data != "")
		{
			i++;//recode current line
			vector<string> line;
			fgets(original_data, sizeof(original_data), fp);//get a line data in .tsv
			my_split(original_data, '\t', line);
			if (line.size() == 0) {
				break;
			}
			if (line[11] != last_eye_movement_type) {//line11 Eye movement type
				//eyeMovementTypeTime.addTime(line[11], stoi(line[12]));
				if (line[11] == "Fixation") {
					//if (line[14] != ""&&line[15] != "") {//line 14,15 Fixation point X,Fixation point Y
					int index = inWhichAOI(atoi(line[14].c_str()), atoi(line[15].c_str()));
					ss << AOIs[index] << "," << line[12] << "->";//line 12 Gaze event duration
					string temp = AOIs[index] + "," + line[12] + "->";
					res.push_back(temp);
					//}
				}
				else if (line[11] == "Saccade") {
					ss << "Saccade" << "," << line[12] << "->";//line 12 Gaze event duration
					string temp = "Saccade," + line[12] + "->";
					res.push_back(temp);
				}
				//else if (line[11] == "Unclassified") {
				//	ss << "Unclassified" << "," << line[12] << "->";//line 12 Gaze event duration
				//	string temp = "Unclassified," + line[12] + "->";
				//	res.push_back(temp);
				//}
			}
			last_eye_movement_type = line[11];

			if (feof(fp))
				break;
		}
		ss << endl;
		ss << "total sequence " << res.size() << endl;

		cout << ss.str() << endl;
		out_file << ss.str() << endl;

		fclose(fp);
	}
	out_file.close();
	system("pause");
*/

/*
	//Sequence3
	FILE *fp;
	const string in_dir = "E:\\read\\";
	const string out_dir = "E:\\out";
	const string out_path = out_dir + "\\Sequence3.txt";
	ofstream out_file(out_path, ofstream::out);
	out_file << "Fixation+Saccade, Continuous state merging1, total sequence XX" << endl;
	string line = "Recording,Sequence";
	//out_file << line << endl;
	//vector<string> names{
	//	"Project77-70 Recording18","Project77-70 Recording26",
	//	"Project77-70 Recording46","Project77-70 Recording70",
	//	"Project63-57 Recording24","Project63-57 Recording28",
	//	"Project63-57 Recording30",
	//	"Project77_56-49 Recording20"
	//};
	vector<string> names{
	"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
	"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
	"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
	"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
	"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
	"Project77_56-49 Recording35","Project77_56-49 Recording38"
	};

	//vector<string> names{
	//"Project77-70 Recording70"
	//};

	string in_path;
	for (int k = 0; k < names.size(); k++) {
		in_path = in_dir + names[k] + ".tsv";
		cout << "第" << k << "个文件路径为：" << in_path << endl;
		fp = fopen(in_path.c_str(), "r");//string to const char*
		if (!fp)
		{
			cout << "OPEN ERROR!" << endl;
			return 0;
		}
		int i = 0;
		EyeMovementTypeTime eyeMovementTypeTime;//8 AOIs
		vector<string> sequence;

		char original_data[1000], data2[1000];
		fgets(original_data, sizeof(original_data), fp);
		const char * split = "\t";
		string last_eye_movement_type = "0";
		int start_flag = 0;
		vector <string> res;//用于记录总数
		out_file << names[k] << "," << endl;
		while (original_data != "")
		{
			i++;//recode current line
			vector<string> line;
			fgets(original_data, sizeof(original_data), fp);//get a line data in .tsv
			my_split(original_data, '\t', line);
			if (line.size() == 0) {
				break;
			}
			if (line[11] != last_eye_movement_type) {//line11 Eye movement type
				//eyeMovementTypeTime.addTime(line[11], stoi(line[12]));
				if (line[11] == "Fixation") {
					//if (line[14] != ""&&line[15] != "") {//line 14,15 Fixation point X,Fixation point Y
					int index = inWhichAOI(atoi(line[14].c_str()), atoi(line[15].c_str()));
					//ss << AOIs[index] << "," << line[12] << "->";//line 12 Gaze event duration
					string temp = AOIs[index] + "," + line[12];// + "->"
					res.push_back(temp);
					//}
				}	
				else if (line[11] == "Saccade") {
					//ss << "Saccade" << "," << line[12] << "->";//line 12 Gaze event duration
					string temp = "Saccade," + line[12];// + "->"
					res.push_back(temp);
				}
			}
			last_eye_movement_type = line[11];

			if (feof(fp))
				break;
		}
		string lastType = "0";
		int flag = 0;//开始有重复
		int type_num = 0, duration = 0;//type重复出现的次数
		int last_duration = 0;
		stringstream ss;

		vector<pair<string, pair<int, int>>> merge_res;
		
		for (int i = 0; i < res.size(); i++) {
			string temp = res[i];
			vector<string> type_duration;
			my_split(temp, ',', type_duration);
			if (merge_res.empty() || type_duration[0] != merge_res.back().first) {
				pair<int, int> num_total(1, stoi(type_duration[1]));
				pair<string, pair<int, int>> temp(type_duration[0], num_total);
			
				merge_res.push_back(temp);
			}
			else if(type_duration[0] == merge_res.back().first){
				merge_res.back().second.second += stoi(type_duration[1]);
				merge_res.back().second.first++;
			}

		}
		for (pair<string, pair<int,int>> a : merge_res) {
			ss << a.first << "," << a.second.first << "," << a.second.second << "->";
		}
		ss << endl;
		ss << "total sequence " << merge_res.size() << endl;
		//cout << ss.str() << endl;
		out_file << ss.str() << endl;
		cout << ss.str() << endl;
		fclose(fp);
	}
	out_file.close();
	system("pause");
*/

/*
	//Sequence4
	//Statement合并
	FILE *fp;
	const string in_dir = "E:\\read\\";
	const string out_dir = "E:\\out";
	const string out_path = out_dir + "\\Sequence4.txt";
	ofstream out_file(out_path, ofstream::out);
	out_file << "Fixation+Saccade, Continuous state merging2(Statement1+Statement2=Statement, without Else), total sequence XX" << endl;
	string line = "Recording,Sequence";
	//out_file << line << endl;
	//vector<string> names{
	//	"Project77-70 Recording18","Project77-70 Recording26",
	//	"Project77-70 Recording46","Project77-70 Recording70",
	//	"Project63-57 Recording24","Project63-57 Recording28",
	//	"Project63-57 Recording30",
	//	"Project77_56-49 Recording20"
	//};

	vector<string> names{
	"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
	"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
	"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
	"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
	"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
	"Project77_56-49 Recording35","Project77_56-49 Recording38"
	};

	//vector<string> names{
	//"Project77-70 Recording46"
	//};

	string in_path;
	for (int k = 0; k < names.size(); k++) {
		in_path = in_dir + names[k] + ".tsv";
		cout << "第" << k << "个文件路径为：" << in_path << endl;
		fp = fopen(in_path.c_str(), "r");//string to const char*
		if (!fp)
		{
			cout << "OPEN ERROR!" << endl;
			return 0;
		}
		int i = 0;
		EyeMovementTypeTime eyeMovementTypeTime;//8 AOIs
		vector<string> sequence;

		char original_data[1000], data2[1000];
		fgets(original_data, sizeof(original_data), fp);
		const char * split = "\t";
		string last_eye_movement_type = "0";
		int start_flag = 0;
		vector <string> res;//用于记录总数
		out_file << names[k] << "," << endl;
		while (fgets(original_data, sizeof(original_data), fp))//original_data != "" !eof(fp)
		{
			i++;//recode current line
			vector<string> line;
			//fgets(original_data, sizeof(original_data), fp);//get a line data in .tsv
			my_split(original_data, '\t', line);
			if (line.size() == 0) {
				break;
			}
			if (line[11] != last_eye_movement_type) {//line11 Eye movement type
				//eyeMovementTypeTime.addTime(line[11], stoi(line[12]));
				if (line[11] == "Fixation") {
					//if (line[14] != ""&&line[15] != "") {//line 14,15 Fixation point X,Fixation point Y
					int index = inWhichAOI2(atoi(line[14].c_str()), atoi(line[15].c_str()));
					//ss << AOIs[index] << "," << line[12] << "->";//line 12 Gaze event duration
					if (index == 7) {//Else不要了
						continue;
					}
					string temp = AOIs2[index] + "," + line[12];// + "->"
					res.push_back(temp);
					//}
				}	
				else if (line[11] == "Saccade") {
					//ss << "Saccade" << "," << line[12] << "->";//line 12 Gaze event duration
					string temp = "Saccade," + line[12];// + "->"
					res.push_back(temp);
				}
			}
			last_eye_movement_type = line[11];

			if (feof(fp))
				break;
		}
		string lastType = "0";
		int flag = 0;//开始有重复
		int type_num = 0, duration = 0;//type重复出现的次数
		int last_duration = 0;
		stringstream ss;

		vector<pair<string, pair<int, int>>> merge_res;
		
		for (int i = 0; i < res.size(); i++) {
			string temp = res[i];
			vector<string> type_duration;
			my_split(temp, ',', type_duration);
			if (merge_res.empty() || type_duration[0] != merge_res.back().first) {
				pair<int, int> num_total(1, stoi(type_duration[1]));
				pair<string, pair<int, int>> temp(type_duration[0], num_total);
			
				merge_res.push_back(temp);
			}
			else if(type_duration[0] == merge_res.back().first){
				merge_res.back().second.second += stoi(type_duration[1]);
				merge_res.back().second.first++;
			}

		}
		for (pair<string, pair<int,int>> a : merge_res) {
			ss << a.first << "," << a.second.first << "," << a.second.second << "->";
		}
		ss << endl;
		ss << "total sequence " << merge_res.size() << endl;
		//cout << ss.str() << endl;
		out_file << ss.str() << endl;
		cout << ss.str() << endl;
		fclose(fp);
	}
	out_file.close();
	system("pause");
*/
/*
	//Sequence5
	vector<string> AOIs2{
		"Diagram","OptionA","OptionB","OptionC","OptionD","Statement","Time","Else"
	};
	//Statement合并
	FILE *fp;
	const string in_dir = "E:\\read\\";
	const string out_dir = "E:\\out";
	const string out_path = out_dir + "\\Sequence5.txt";
	ofstream out_file(out_path, ofstream::out);
	out_file << "Fixation, Continuous state merging(Statement1+Statement2=Statement, without Else), total sequence XX" << endl;
	string line = "Recording,Sequence";
	//out_file << line << endl;
	//vector<string> names{
	//	"Project77-70 Recording18","Project77-70 Recording26",
	//	"Project77-70 Recording46","Project77-70 Recording70",
	//	"Project63-57 Recording24","Project63-57 Recording28",
	//	"Project63-57 Recording30",
	//	"Project77_56-49 Recording20"
	//};

	vector<string> names{
	"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
	"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
	"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
	"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
	"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
	"Project77_56-49 Recording35","Project77_56-49 Recording38"
	};

	//vector<string> names{
	//"Project77-70 Recording46"
	//};

	string in_path;
	for (int k = 0; k < names.size(); k++) {
		in_path = in_dir + names[k] + ".tsv";
		cout << "第" << k << "个文件路径为：" << in_path << endl;
		fp = fopen(in_path.c_str(), "r");//string to const char*
		if (!fp)
		{
			cout << "OPEN ERROR!" << endl;
			return 0;
		}
		int i = 0;
		EyeMovementTypeTime eyeMovementTypeTime;//8 AOIs
		vector<string> sequence;

		char original_data[1000], data2[1000];
		fgets(original_data, sizeof(original_data), fp);
		const char * split = "\t";
		string last_eye_movement_type = "0";
		int start_flag = 0;
		vector <string> res;//用于记录总数
		out_file << names[k] << "," << endl;
		while (fgets(original_data, sizeof(original_data), fp))//original_data != "" !eof(fp)
		{
			i++;//recode current line
			vector<string> line;
			//fgets(original_data, sizeof(original_data), fp);//get a line data in .tsv
			my_split(original_data, '\t', line);
			if (line.size() == 0) {
				break;
			}
			if (line[11] != last_eye_movement_type) {//line11 Eye movement type
				//eyeMovementTypeTime.addTime(line[11], stoi(line[12]));
				if (line[11] == "Fixation") {
					//if (line[14] != ""&&line[15] != "") {//line 14,15 Fixation point X,Fixation point Y
					int index = inWhichAOI2(atoi(line[14].c_str()), atoi(line[15].c_str()));
					//ss << AOIs[index] << "," << line[12] << "->";//line 12 Gaze event duration
					if (index == 7) {//Else不要了
						continue;
					}
					string temp = AOIs2[index] + "," + line[12];// + "->"
					res.push_back(temp);
					//}
				}	
				//else if (line[11] == "Saccade") {
				//	//ss << "Saccade" << "," << line[12] << "->";//line 12 Gaze event duration
				//	string temp = "Saccade," + line[12];// + "->"
				//	res.push_back(temp);
				//}
			}
			last_eye_movement_type = line[11];

			if (feof(fp))
				break;
		}
		string lastType = "0";
		int flag = 0;//开始有重复
		int type_num = 0, duration = 0;//type重复出现的次数
		int last_duration = 0;
		stringstream ss;

		vector<pair<string, pair<int, int>>> merge_res;
		
		for (int i = 0; i < res.size(); i++) {
			string temp = res[i];
			vector<string> type_duration;
			my_split(temp, ',', type_duration);
			if (merge_res.empty() || type_duration[0] != merge_res.back().first) {
				pair<int, int> num_total(1, stoi(type_duration[1]));
				pair<string, pair<int, int>> temp(type_duration[0], num_total);
			
				merge_res.push_back(temp);
			}
			else if(type_duration[0] == merge_res.back().first){
				merge_res.back().second.second += stoi(type_duration[1]);
				merge_res.back().second.first++;
			}

		}
		for (pair<string, pair<int,int>> a : merge_res) {
			ss << a.first << "," << a.second.first << "," << a.second.second << "->";
		}
		ss << endl;
		ss << "total sequence " << merge_res.size() << endl;
		//cout << ss.str() << endl;
		out_file << ss.str() << endl;
		cout << ss.str() << endl;
		fclose(fp);
	}
	out_file.close();
	system("pause");
*/

/*
	//Sequence6在3的基础,读取的表是所有属性表
	FILE *fp;
	const string in_dir = "E:\\read-all\\";
	const string out_dir = "E:\\out";
	const string out_path = out_dir + "\\Sequence6.txt";
	ofstream out_file(out_path, ofstream::out);
	out_file << "Fixation+Saccade+Unclassified, Continuous state merging2, total sequence XX" << endl;
	string line = "Recording,Sequence";
	//out_file << line << endl;
	//vector<string> names{
	//	"Project77-70 Recording18","Project77-70 Recording26",
	//	"Project77-70 Recording46","Project77-70 Recording70",
	//	"Project63-57 Recording24","Project63-57 Recording28",
	//	"Project63-57 Recording30",
	//	"Project77_56-49 Recording20"
	//};
	vector<string> names{
	"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
	"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
	"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
	"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
	"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
	"Project77_56-49 Recording35","Project77_56-49 Recording38"
	};

	//vector<string> names{
	//"Project77-70 Recording70"
	//};

	string in_path;
	for (int k = 0; k < names.size(); k++) {
		in_path = in_dir + names[k] + ".tsv";
		cout << "第" << k << "个文件路径为：" << in_path << endl;
		fp = fopen(in_path.c_str(), "r");//string to const char*
		if (!fp)
		{
			cout << "OPEN ERROR!" << endl;
			return 0;
		}
		int i = 0;
		EyeMovementTypeTime eyeMovementTypeTime;//8 AOIs
		vector<string> sequence;

		char original_data[20000], data2[1000];
		fgets(original_data, sizeof(original_data), fp);
		const char * split = "\t";
		string last_eye_movement_type = "0";
		int start_flag = 0;
		vector <string> res;//用于记录总数
		out_file << names[k] << "," << endl;
		while (original_data != "")
		{
			i++;//recode current line
			vector<string> line;
			fgets(original_data, sizeof(original_data), fp);//get a line data in .tsv
			my_split(original_data, '\t', line);
			if (line.size() == 0) {
				break;
			}
			// 11->54 :Eye movement type; 
			// 12->55 Gaze event duration;
			// 14,15->26,27 Fixation point X/Y->Gaze point X/Y;
			// 14,15->57，58 Fixation point 
			if (line[54] != last_eye_movement_type) {//line11 Eye movement type
				//eyeMovementTypeTime.addTime(line[11], stoi(line[12]));
				if (line[54] == "Fixation") {
					//if (line[14] != ""&&line[15] != "") {//line 14,15 Fixation point X,Fixation point Y
					int index = inWhichAOI(atoi(line[57].c_str()), atoi(line[58].c_str()));
					//ss << AOIs[index] << "," << line[12] << "->";//line 12 Gaze event duration
					string temp = AOIs[index] + "(F)," + line[55];// + "->"
					res.push_back(temp);
					//}
				}
				else if (line[54] == "Saccade") {
					//ss << "Saccade" << "," << line[12] << "->";//line 12 Gaze event duration

					int index = inWhichAOI(atoi(line[26].c_str()), atoi(line[27].c_str()));
					string temp = AOIs[index] + "(S)," + line[55];// + "->"
					res.push_back(temp);
				}
				else if (line[54] == "Unclassified") {

					int index = inWhichAOI(atoi(line[26].c_str()), atoi(line[27].c_str()));
					string temp = AOIs[index] + "(U)," + line[55];// + "->"
					res.push_back(temp);
				}

			}
			last_eye_movement_type = line[54];

			if (feof(fp))
				break;
		}
		string lastType = "0";
		int flag = 0;//开始有重复
		int type_num = 0, duration = 0;//type重复出现的次数
		int last_duration = 0;
		stringstream ss;

		vector<pair<string, pair<int, int>>> merge_res;

		for (int i = 0; i < res.size(); i++) {
			string temp = res[i];
			vector<string> type_duration;
			my_split(temp, ',', type_duration);
			if (merge_res.empty() || type_duration[0] != merge_res.back().first) {
				pair<int, int> num_total(1, stoi(type_duration[1]));
				pair<string, pair<int, int>> temp(type_duration[0], num_total);

				merge_res.push_back(temp);
			}
			else if (type_duration[0] == merge_res.back().first) {
				merge_res.back().second.second += stoi(type_duration[1]);
				merge_res.back().second.first++;
			}

		}
		for (pair<string, pair<int, int>> a : merge_res) {
			ss << a.first << "," << a.second.first << "," << a.second.second << "->";
		}
		ss << endl;
		ss << "total sequence " << merge_res.size() << endl;
		//cout << ss.str() << endl;
		out_file << ss.str() << endl;
		cout << ss.str() << endl;
		fclose(fp);
	}
	out_file.close();
	system("pause");
*/

/*
	//Sequence7 不分类型了
	FILE *fp;
	const string in_dir = "E:\\read-all\\";
	const string out_dir = "E:\\out";
	const string out_path = out_dir + "\\Sequence7.txt";
	ofstream out_file(out_path, ofstream::out);
	out_file << "AOIs, Continuous state merging2, total sequence XX" << endl;
	string line = "Recording,Sequence";
	//out_file << line << endl;
	//vector<string> names{
	//	"Project77-70 Recording18","Project77-70 Recording26",
	//	"Project77-70 Recording46","Project77-70 Recording70",
	//	"Project63-57 Recording24","Project63-57 Recording28",
	//	"Project63-57 Recording30",
	//	"Project77_56-49 Recording20"
	//};

	//vector<string> names{
	//"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
	//"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
	//"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
	//"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
	//"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
	//"Project77_56-49 Recording35","Project77_56-49 Recording38"
	//};

	vector<string> names{
		"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
		"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
		"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
		"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
		"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
		"Project77_56-49 Recording35","Project77_56-49 Recording38",
		"Project48-39 Recording19","Project48-39 Recording29","Project48-39 Recording34",
		"Project48-39 Recording40","Project48-39 Recording45","Project48-39 Recording47",
		"Project48-39 Recording49","Project48-39 Recording52","Project48-39 Recording55",
		"Project48-39 Recording71",
		"Project33-24 Recording16","Project33-24 Recording17","Project33-24 Recording36",
		"Project33-24 Recording37","Project33-24 Recording39","Project33-24 Recording41",
		"Project33-24 Recording57","Project33-24 Recording59","Project33-24 Recording65",
		"Project33-24 Recording66","Project33-24 Recording67","Project33-24 Recording68",
		"Project33-24 Recording72",
		"Project22-1 Recording42","Project22-1 Recording48","Project22-1 Recording50",
		"Project22-1 Recording51","Project22-1 Recording53","Project22-1 Recording54",
		"Project22-1 Recording56","Project22-1 Recording58","Project22-1 Recording61",
		"Project22-1 Recording62","Project22-1 Recording64","Project22-1 Recording69"
	};

	//vector<string> names{
	//"Project77-70 Recording70"
	//};

	string in_path;
	for (int k = 0; k < names.size(); k++) {
		in_path = in_dir + names[k] + ".tsv";
		cout << "第" << k << "个文件路径为：" << in_path << endl;
		fp = fopen(in_path.c_str(), "r");//string to const char*
		if (!fp)
		{
			cout << "OPEN ERROR!" << endl;
			return 0;
		}
		int i = 0;
		EyeMovementTypeTime eyeMovementTypeTime;//8 AOIs
		vector<string> sequence;

		char original_data[20000], data2[1000];
		fgets(original_data, sizeof(original_data), fp);
		const char * split = "\t";
		string last_eye_movement_type = "0";
		int start_flag = 0;
		vector <string> res;//用于记录总数
		out_file << names[k] << "," << endl;
		while (fgets(original_data, sizeof(original_data), fp))
		{
			i++;//recode current line
			vector<string> line;
			//;get a line data in .tsv
			my_split(original_data, '\t', line);
			if (line.size() == 0) {
				break;
			}
			// 11->54 :Eye movement type; 
			// 12->55 Gaze event duration;
			// 14,15->26,27 Fixation point X/Y->Gaze point X/Y;
			// 14,15->57，58 Fixation point 
			if (line[54] != last_eye_movement_type) {//line11 Eye movement type
				//eyeMovementTypeTime.addTime(line[11], stoi(line[12]));
				if (line[54] == "Fixation") {
					//if (line[14] != ""&&line[15] != "") {//line 14,15 Fixation point X,Fixation point Y
					int index = inWhichAOI2(atoi(line[57].c_str()), atoi(line[58].c_str()));
					//ss << AOIs[index] << "," << line[12] << "->";//line 12 Gaze event duration
					if (index == 7) {//Else不要了
						continue;
					}
					string temp = AOIs2[index] + "," + line[55];// + "->"
					res.push_back(temp);
					//}
				}
				else if (line[54] == "Saccade") {
					//ss << "Saccade" << "," << line[12] << "->";//line 12 Gaze event duration

					int index = inWhichAOI2(atoi(line[26].c_str()), atoi(line[27].c_str()));
					if (index == 7) {//Else不要了
						continue;
					}
					string temp = AOIs2[index] + "," + line[55];// + "->"
					res.push_back(temp);
				}
				else if (line[54] == "Unclassified") {

					int index = inWhichAOI2(atoi(line[26].c_str()), atoi(line[27].c_str()));
					if (index == 7) {//Else不要了
						continue;
					}
					string temp = AOIs2[index] + "," + line[55];// + "->"
					res.push_back(temp);
				}

			}
			last_eye_movement_type = line[54];

			if (feof(fp))
				break;
		}
		string lastType = "0";
		int flag = 0;//开始有重复
		int type_num = 0, duration = 0;//type重复出现的次数
		int last_duration = 0;
		stringstream ss;

		vector<pair<string, pair<int, int>>> merge_res;

		for (int i = 0; i < res.size(); i++) {
			string temp = res[i];
			vector<string> type_duration;
			my_split(temp, ',', type_duration);
			if (merge_res.empty() || type_duration[0] != merge_res.back().first) {
				pair<int, int> num_total(1, stoi(type_duration[1]));
				pair<string, pair<int, int>> temp(type_duration[0], num_total);

				merge_res.push_back(temp);
			}
			else if (type_duration[0] == merge_res.back().first) {
				merge_res.back().second.second += stoi(type_duration[1]);
				merge_res.back().second.first++;
			}

		}
		for (pair<string, pair<int, int>> a : merge_res) {
			ss << a.first << "," << a.second.first << "," << a.second.second << "->";
		}
		ss << endl;
		ss << "total sequence " << merge_res.size() << endl;
		//cout << ss.str() << endl;
		out_file << ss.str() << endl;
		cout << ss.str() << endl;
		fclose(fp);
	}
	out_file.close();
	system("pause");
*/

/*
	//Sequence7多文件 不分类型了
	FILE *fp;
	const string in_dir = "E:\\read-all\\";
	const string out_dir = "E:\\out\\user\\";
	vector<string> names{
		"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
		"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
		"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
		"Project63-57 Recording30","Project63-57 Recording32","Project63-57 Recording63",
		"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
		"Project77_56-49 Recording35","Project77_56-49 Recording38",
		"Project48-39 Recording19","Project48-39 Recording29","Project48-39 Recording34",
		"Project48-39 Recording40","Project48-39 Recording45","Project48-39 Recording47",
		"Project48-39 Recording49","Project48-39 Recording52","Project48-39 Recording55",
		"Project48-39 Recording71",
		"Project33-24 Recording16","Project33-24 Recording17","Project33-24 Recording36",
		"Project33-24 Recording37","Project33-24 Recording39","Project33-24 Recording41",
		"Project33-24 Recording57","Project33-24 Recording59","Project33-24 Recording65",
		"Project33-24 Recording66","Project33-24 Recording67","Project33-24 Recording68",
		"Project33-24 Recording72",
		"Project22-1 Recording42","Project22-1 Recording48","Project22-1 Recording50",
		"Project22-1 Recording51","Project22-1 Recording53","Project22-1 Recording54",
		"Project22-1 Recording56","Project22-1 Recording58","Project22-1 Recording61",
		"Project22-1 Recording62","Project22-1 Recording64","Project22-1 Recording69"
	};

	//vector<string> names{
	//	"Project63-57 Recording23"
	//};

	string in_path;
	for (int k = 0; k < names.size(); k++) {
		in_path = in_dir + names[k] + ".tsv";
		cout << "第" << k << "个文件路径为：" << in_path << endl;

		const string out_path = out_dir  + names[k] + ".txt";
		ofstream out_file(out_path, ofstream::out);

		fp = fopen(in_path.c_str(), "r");//string to const char*
		if (!fp)
		{
			cout << "OPEN ERROR!" << endl;
			return 0;
		}
		int i = 0;
		EyeMovementTypeTime eyeMovementTypeTime;//8 AOIs
		vector<string> sequence;

		char original_data[20000], data2[1000];
		fgets(original_data, sizeof(original_data), fp);
		const char * split = "\t";
		string last_eye_movement_type = "0";
		int start_flag = 0;
		vector <string> res;//用于记录总数
		while (fgets(original_data, sizeof(original_data), fp))
		{
			i++;//recode current line
			vector<string> line;
			//;get a line data in .tsv
			my_split(original_data, '\t', line);
			if (line.size() == 0) {
				break;
			}
			// 11->54 :Eye movement type; 
			// 12->55 Gaze event duration;
			// 14,15->26,27 Fixation point X/Y->Gaze point X/Y;
			// 14,15->57，58 Fixation point 
			if (line[54] != last_eye_movement_type) {//line11 Eye movement type
				//eyeMovementTypeTime.addTime(line[11], stoi(line[12]));
				if (line[54] == "Fixation") {
					//if (line[14] != ""&&line[15] != "") {//line 14,15 Fixation point X,Fixation point Y
					int index = inWhichAOI2(atoi(line[57].c_str()), atoi(line[58].c_str()));
					//ss << AOIs[index] << "," << line[12] << "->";//line 12 Gaze event duration
					if (index == 7) {//Else不要了
						continue;
					}
					string temp = AOIs2[index] + "," + line[55];// + "->"
					res.push_back(temp);
					//}
				}
				else if (line[54] == "Saccade") {
					//ss << "Saccade" << "," << line[12] << "->";//line 12 Gaze event duration

					int index = inWhichAOI2(atoi(line[26].c_str()), atoi(line[27].c_str()));
					if (index == 7) {//Else不要了
						continue;
					}
					string temp = AOIs2[index] + "," + line[55];// + "->"
					res.push_back(temp);
				}
				else if (line[54] == "Unclassified") {

					int index = inWhichAOI2(atoi(line[26].c_str()), atoi(line[27].c_str()));
					if (index == 7) {//Else不要了
						continue;
					}
					string temp = AOIs2[index] + "," + line[55];// + "->"
					res.push_back(temp);
				}

			}
			last_eye_movement_type = line[54];

			if (feof(fp))
				break;
		}
		string lastType = "0";
		int flag = 0;//开始有重复
		int type_num = 0, duration = 0;//type重复出现的次数
		int last_duration = 0;
		stringstream ss;

		vector<pair<string, pair<int, int>>> merge_res;

		for (int i = 0; i < res.size(); i++) {
			string temp = res[i];
			vector<string> type_duration;
			my_split(temp, ',', type_duration);
			if (merge_res.empty() || type_duration[0] != merge_res.back().first) {
				pair<int, int> num_total(1, stoi(type_duration[1]));
				pair<string, pair<int, int>> temp(type_duration[0], num_total);

				merge_res.push_back(temp);
			}
			else if (type_duration[0] == merge_res.back().first) {
				merge_res.back().second.second += stoi(type_duration[1]);
				merge_res.back().second.first++;
			}

		}
		for (pair<string, pair<int, int>> a : merge_res) {
			ss << a.first << "," << a.second.first << "," << a.second.second << endl;
		}
		//ss << "total sequence " << merge_res.size() << endl;
		//cout << ss.str() << endl;
		out_file << ss.str() << endl;
		cout << ss.str() << endl;
		fclose(fp);

		out_file.close();
	}
	system("pause");
*/

	//Sequence8相比Sequence7 Option合并了
	FILE *fp;
	const string in_dir = "E:\\read-all\\";
	const string out_dir = "E:\\out\\user\\";
	//vector<string> names{//correct
	//	"Project77-70 Recording18","Project77-70 Recording25","Project77-70 Recording26",
	//	"Project77-70 Recording31","Project77-70 Recording46","Project77-70 Recording70",
	//	"Project63-57 Recording23","Project63-57 Recording24","Project63-57 Recording28",
	//	"Project63-57 Recording32","Project63-57 Recording63",
	//	"Project77_56-49 Recording20","Project77_56-49 Recording27","Project77_56-49 Recording33",
	//	"Project77_56-49 Recording35","Project77_56-49 Recording38",
	//	"Project48-39 Recording19","Project48-39 Recording29","Project48-39 Recording34",
	//	"Project48-39 Recording40","Project48-39 Recording45","Project48-39 Recording47",
	//	"Project48-39 Recording49","Project48-39 Recording55",
	//	
	//	"Project33-24 Recording17","Project33-24 Recording36",
	//	"Project33-24 Recording37","Project33-24 Recording39",
	//	"Project33-24 Recording57","Project33-24 Recording59","Project33-24 Recording65",
	//	"Project33-24 Recording66","Project33-24 Recording67",
	//	"Project33-24 Recording72",
	//	"Project22-1 Recording50",
	//	"Project22-1 Recording51",
	//	"Project22-1 Recording58","Project22-1 Recording61",
	//	"Project22-1 Recording62","Project22-1 Recording64"
	//};
	
	vector<string> names{//incorrect
		"Project63-57 Recording30","Project48-39 Recording71","Project48-39 Recording52",
		"Project33-24 Recording68","Project33-24 Recording41","Project33-24 Recording16",
		"Project22-1 Recording56","Project22-1 Recording53","Project22-1 Recording42",
		"Project22-1 Recording48","Project22-1 Recording54","Project22-1 Recording69"
	};

	//vector<string> names{
	//	"Project77-70 Recording70"
	//};

	string in_path;
	for (int k = 0; k < names.size(); k++) {
		in_path = in_dir + names[k] + ".tsv";
		cout << "第" << k << "个文件路径为：" << in_path << endl;

		const string out_path = out_dir + names[k] + ".txt";
		ofstream out_file(out_path, ofstream::out);

		fp = fopen(in_path.c_str(), "r");//string to const char*
		if (!fp)
		{
			cout << "OPEN ERROR!" << endl;
			return 0;
		}
		int i = 0;
		EyeMovementTypeTime eyeMovementTypeTime;//8 AOIs
		vector<string> sequence;

		char original_data[20000], data2[1000];
		fgets(original_data, sizeof(original_data), fp);
		const char * split = "\t";
		string last_eye_movement_type = "0";
		int start_flag = 0;
		vector <string> res;//用于记录总数
		while (fgets(original_data, sizeof(original_data), fp))
		{
			i++;//recode current line
			vector<string> line;
			//;get a line data in .tsv
			my_split(original_data, '\t', line);
			if (line.size() == 0) {
				break;
			}
			// 11->54 :Eye movement type; 
			// 12->55 Gaze event duration;
			// 14,15->26,27 Fixation point X/Y->Gaze point X/Y;
			// 14,15->57，58 Fixation point 
			if (line[54] != last_eye_movement_type) {//line11 Eye movement type
				//eyeMovementTypeTime.addTime(line[11], stoi(line[12]));
				if (line[54] == "Fixation") {
					//if (line[14] != ""&&line[15] != "") {//line 14,15 Fixation point X,Fixation point Y
					int index = inWhichAOI3(atoi(line[57].c_str()), atoi(line[58].c_str()));
					//ss << AOIs[index] << "," << line[12] << "->";//line 12 Gaze event duration
					if (index == 4) {//Else不要了
						continue;
					}
					string temp = AOIs3[index] + "," + line[55];// + "->"
					res.push_back(temp);
					//}
				}
				else if (line[54] == "Saccade") {
					//ss << "Saccade" << "," << line[12] << "->";//line 12 Gaze event duration

					int index = inWhichAOI3(atoi(line[26].c_str()), atoi(line[27].c_str()));
					if (index == 4) {//Else不要了
						continue;
					}
					string temp = AOIs3[index] + "," + line[55];// + "->"
					res.push_back(temp);
				}
				else if (line[54] == "Unclassified") {

					int index = inWhichAOI3(atoi(line[26].c_str()), atoi(line[27].c_str()));
					if (index == 4) {//Else不要了
						continue;
					}
					string temp = AOIs3[index] + "," + line[55];// + "->"
					res.push_back(temp);
				}

			}
			last_eye_movement_type = line[54];

			if (feof(fp))
				break;
		}
		string lastType = "0";
		int flag = 0;//开始有重复
		int type_num = 0, duration = 0;//type重复出现的次数
		int last_duration = 0;
		stringstream ss;

		vector<pair<string, pair<int, int>>> merge_res;

		for (int i = 0; i < res.size(); i++) {
			string temp = res[i];
			vector<string> type_duration;
			my_split(temp, ',', type_duration);
			if (merge_res.empty() || type_duration[0] != merge_res.back().first) {
				pair<int, int> num_total(1, stoi(type_duration[1]));
				pair<string, pair<int, int>> temp(type_duration[0], num_total);

				merge_res.push_back(temp);
			}
			else if (type_duration[0] == merge_res.back().first) {
				merge_res.back().second.second += stoi(type_duration[1]);
				merge_res.back().second.first++;
			}

		}
		for (pair<string, pair<int, int>> a : merge_res) {
			ss << a.first << "," << a.second.first << "," << a.second.second << endl;
		}
		//ss << "total sequence " << merge_res.size() << endl;
		//cout << ss.str() << endl;
		out_file << ss.str() << endl;
		cout << ss.str() << endl;
		fclose(fp);

		out_file.close();
	}
	system("pause");


}