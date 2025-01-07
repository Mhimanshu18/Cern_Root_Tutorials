void tut19()
{
    TCanvas *c1 = new TCanvas();

    TProfile *hprof = new TProfile("hprof", "Profile", 100, 0, 10, "S");


    TRandom2 *rand = new TRandom2();

    for(int i = 0; i < 1000; i++)
    {
        hprof->Fill(rand->Rndm()*10, rand->Rndm());
    }


    

    hprof->Draw();
    }