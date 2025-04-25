#include <iostream>
#include <vector>
#include <wx/wx.h>
#include "ActivityLog.h"
#include "MainFrame.h"

class App : public wxApp{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* frame = new MainFrame("Activity Log");
    frame->SetClientSize(500, 600);
    frame->Center();
    frame->Show(true);
    return true;
}

/*
int main() {
    using namespace std;

    struct activity a;
    struct activity b;

    struct time aStart = {12, 30};
    struct time aEnd = {17, 30};

    struct time bStart = {8, 30};
    struct time bEnd = {14, 15};

    a.title = "Campeggio";
    a.description = "Lets go to the campeggio";
    a.start = aStart;
    a.end = aEnd;

    b.title = "Camminata";
    b.description = "Lets go camminare";
    b.start = bStart;
    b.end = bEnd;

    ActivityLog* giorno = new ActivityLog();

    giorno->addActivity(b);
    giorno->addActivity(a);

    string s = "Camminatas";

    return 0;
}
*/