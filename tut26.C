void tut26()
{
    TCanvas *c1 = new TCanvas("c1", "c1", 300, 300);

    TEllipse *el = new TEllipse(0.5, 0.5, 0.1, 0.1);

    el->SetFillColor(kBlack);

    gSystem->Unlink("tut26.gif");

    for(int i = 0; i < 50; i++)
    {
        el->SetX1(0.5+i*0.1);
        el->Draw();
        c1->Update();
        c1->Print("tut26.gif+");
        //sleep(1);
    }


}