//
// Created by Dardan Matias Berisha on 06/07/23.
//

#include "DialogAddDay.h"
#include <wx/calctrl.h>

DialogAddDay::DialogAddDay(const wxString &title, MainFrame *mainFrame):
    wxDialog(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 250)),
    mainFrame(mainFrame){

    auto panel = new wxPanel(this);
    text = new wxStaticText(panel, wxID_ANY, "Choose a date", wxPoint(10, 10));
    calendar = new wxCalendarCtrl(panel, wxID_ANY, wxDateTime::Now(), wxPoint(10, 10 + text->GetSize().y + 10), wxSize(-1, -1));
    auto addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(10, 187), wxSize(100, 30));
    auto closeButton = new wxButton(panel, wxID_ANY, "Close", wxPoint(10 + addButton->GetSize().x + 10, 187), wxSize(100, 30));

    closeButton->Bind(wxEVT_BUTTON, &DialogAddDay::OnCloseButtonClicked, this);
    addButton->Bind(wxEVT_BUTTON, &DialogAddDay::OnAddButtonClicked, this);
}

void DialogAddDay::OnAddButtonClicked(wxCommandEvent &event) {
    std::stringstream str;
    int day, month;
    day = calendar->GetDate().GetDay();
    month = calendar->GetDate().GetMonth() + 1;
    std::stringstream strDay, strMonth;
    if(day < 10)
        strDay << "0" << day;
    else
        strDay << day;

    if(month < 10)
        strMonth << "0" << month;
    else
        strMonth << month;

    str << calendar->GetDate().GetYear() << "/" << strMonth.str() << "/" << strDay.str();
    std::string chosenDate = str.str();
    if(mainFrame->addDay(chosenDate))
        Close();
    else
        wxMessageBox("The date you chose is already in the list");

}

void DialogAddDay::OnCloseButtonClicked(wxCommandEvent &event) {
    Close();
}
