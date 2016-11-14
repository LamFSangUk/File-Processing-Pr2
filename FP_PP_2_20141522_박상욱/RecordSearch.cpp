#include "RecordSearch.h"

void RecordSearch() {

	while (1) {
		system("cls");

		cout << " -Record-Search----------------" << endl;
		cout << " 1. Member Records Search" << endl;
		cout << " 2. Stock Records Search" << endl;
		cout << " 3. Purchase Records Search" << endl;
		cout << " 4. Exit to AdminMode" << endl;
		cout << " ------------------------------" << endl;
		cout << ">> ";

		int mode;
		cin >> mode;
		cin.ignore();

		string input;
		Member m;
		Stock s;
		int find_flag=-1;

		switch (mode) {
		case 1: 

			cout << " Please Input your Member ID : ";

			cin >> input;

			m=MemberSearch(input,&find_flag);

			if(find_flag>=0){//Find Success
				cout << m;
			}
			else{
				cout << " There is Not Correct Member ID" << endl;
			}
			cout << " Press any button to return to AdminMode" << endl;
			cout << ">> ";
			_getch();
			return;

		case 2: 
			cout << " Please Input your Stock ID : ";

			cin >> input;

			s=StockSearch(input,&find_flag);

			if(find_flag>=0){//Find Success
				cout << s;
			}
			else{
				cout << " There is Not Correct Stock ID" << endl;
			}
			cout << " Press any button to return to AdminMode" << endl;
			cout << ">> ";
			_getch();
			return;

		case 3: 
			PurchaseSearch();
			break;
		case 4: return;
		default: 
			cin.clear();
			break;

		}


	}
	return;
}

Member MemberSearch(string id,int *flag) {

	// Read and Write with TextIndexedFile
	DelimFieldBuffer buf ('|', STDMAXBUF);
	TextIndexedFile<Member> StdIdxedFile(buf, LENID,10000);
	StdIdxedFile.Open ("fileOfMember");

	Member m;
	int find=StdIdxedFile.Read ((char*)id.c_str(), m);	

	*flag=find;

	return m;
}

Stock StockSearch(string id,int *flag){
	DelimFieldBuffer buf ('|', STDMAXBUF);
	TextIndexedFile<Stock> StdIdxedFile(buf, LENID,10000);
	StdIdxedFile.Open ("fileOfStock");

	Stock s;
	int find=StdIdxedFile.Read ((char*)id.c_str(), s);	

	*flag=find;

	return s;
}

void PurchaseSearch() {
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile<Purchase> PurchaseFile(buffer);

	int searchmode;
	while (1) {
		system("cls");
		cout << " -Purchase Search--------------" << endl;
		cout << " 1. Search with Purchase ID" << endl;
		cout << " 2. Search with Stock ID" << endl;
		cout << " 3. Search with Member ID" << endl;
		cout << " 4. Exit to Search Menu" << endl;
		cout << " ------------------------------" << endl;
		cout << ">> ";

		cin >> searchmode;
		cin.ignore();

		if (searchmode == 1) {
			cout << " Please Input the Purchase ID : ";

			string input;
			cin >> input;

			Purchase result;

			PurchaseFile.Open("fileOfPurchase.dat", ios::in);

			int idx = Purchasemap[input];
			if (idx == 0) {
				cout << "There is Not Correct Purchase ID" << endl;
			}
			else {
				PurchaseFile.Read(result, Purchasemap[input]);

				cout << result;
			}
			cout << " Press any button to return to Record Search" << endl;
			cout << ">> ";
			_getch();

			PurchaseFile.Close();

			return;
		}
		else if (searchmode == 2) {
			cout << " Please Input the Stock ID : ";

			string input;
			cin >> input;

			Purchase result;

			PurchaseFile.Open("fileOfPurchase.dat", ios::in);

			int datacount = PMwithStock[input].size();
			if (datacount == 0) {
				cout << "There is Not Correct Stock ID" << endl;
			}
			else {
				for (int i = 0; i < datacount; i++) {
					PurchaseFile.Read(result, PMwithStock[input][i]);

					cout << result;
				}
			}
			cout << " Press any button to return to Record Search" << endl;
			cout << ">> ";
			_getch();

			PurchaseFile.Close();

			return;
		}
		else if (searchmode == 3) {
			cout << " Please Input the Member ID : ";

			string input;
			cin >> input;

			Purchase result;

			PurchaseFile.Open("fileOfPurchase.dat", ios::in);

			int datacount = PMwithMember[input].size();
			if (datacount == 0) {
				cout << "There is Not Correct Member ID" << endl;
			}
			else {
				for (int i = 0; i < datacount; i++) {
					PurchaseFile.Read(result, PMwithMember[input][i]);

					cout << result;
				}
			}
			cout << " Press any button to return to Record Search" << endl;
			cout << ">> ";
			_getch();

			PurchaseFile.Close();

			return;
		}
		else if (searchmode == 4) break;
		else {
			continue;
		}
	}

	return;
}

void PurchaseSearch(string user_id) {
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile<Purchase> PurchaseFile(buffer);

	system("cls");

	cout << " -My Purchase List-------------" << endl;
	Purchase result;

	PurchaseFile.Open("fileOfPurchase.dat", ios::in);

	int datacount = PMwithMember[user_id].size();
	if (datacount == 0) {
		cout << "There is Not Correct Member ID" << endl;
	}
	else {
		for (int i = 0; i < datacount; i++) {
			PurchaseFile.Read(result, PMwithMember[user_id][i]);

			cout << result;
		}
	}
	cout << " Press any button to return to Record Search" << endl;
	cout << ">> ";
	_getch();

	PurchaseFile.Close();

	return;

}