void tut27() {
    TCanvas *c1 = new TCanvas("c1", "Canvas for GIF", 300, 300);
    TEllipse *el = new TEllipse(0.5, 0.5, 0.1, 0.1);
    el->SetFillColor(kRed);

    // Delete existing GIF file
    gSystem->Unlink("tut26.gif");

    // Generate frames
    for (int i = 0; i < 50; i++) {
        el->SetX1(0.5 + i * 0.01); // Update ellipse position
        el->Draw();
        c1->Update();
        c1->Print("tut26.gif+"); // Append frame to GIF
        gSystem->Sleep(50); // Delay for smooth frame generation
    }

    std::cout << "GIF saved as tut26.gif" << std::endl;

    // Clean up
    delete el;
    delete c1;
}
