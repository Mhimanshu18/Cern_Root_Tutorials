import ROOT

h1 = ROOT.TH1F("h1"," Random ",200, -5, 5)

h1.FillRandom("gaus")

c1 = ROOT.TCanvas()

h1.Draw()
#input()
c1.Print("c1.pdf")