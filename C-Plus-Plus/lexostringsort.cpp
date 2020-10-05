Sort a List of strings Lexographically

/*bool compare(string a, string b) { // This Comparator is being used
	// Strings for same length then they are sorted lexographically, otherwise
	// Strings get sorted on basis of length
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() > b.length();
	}
}

string stringsort() {
	int n;
	cin >> n;
	cin.get();

	string s[100];

	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}


	sort(s, s + n, compare);

	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}

}*/
