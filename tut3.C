void tut3()
{
	TH1F *hist = new TH1F("hist", "Histogram", 10, 10 , 38);
	
	fstream file;
    file.open("data.txt", ios::in);

    double value;

    while(1)
    {
        file>>value;
        hist->Fill(value);
        if(file.eof()) break;

    }

    file.close();

    
	hist-> GetXaxis()->SetTitle("Grades");
	hist-> GetYaxis()->SetTitle("Entries");

	TCanvas *c1= new TCanvas();
	hist-> Draw();

}