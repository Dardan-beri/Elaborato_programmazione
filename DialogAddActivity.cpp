//
// Created by Dardan Matias Berisha on 07/07/23.
//

#include "DialogAddActivity.h"
#include <wx/spinctrl.h>

DialogAddActivity::DialogAddActivity(MainFrame *mainFrame, wxString day) :
    wxDialog(nullptr, wxID_ANY, "Add activity to " + day.ToStdString(), wxDefaultPosition, wxSize(300, 200)),
    mainFrame(mainFrame),
    day(day) {
    wxPanel* panel = new wxPanel(this);

    titleCtrl = new wxTextCtrl(panel, wxID_ANY, "Title", wxPoint(10, 10), wxSize(250, -1));
    descriptionCtrl = new wxTextCtrl(panel, wxID_ANY, "Description", wxPoint(10, 10 + titleCtrl->GetSize().y + 10), wxSize(250, -1));

    wxStaticText* startTimeText = new wxStaticText(panel, wxID_ANY, "Start time [hr/min]", wxPoint(10, 10 + titleCtrl->GetSize().y + 10 + descriptionCtrl->GetSize().y + 10));
    startHour = new wxSpinCtrl(panel, wxID_ANY, "0", wxPoint(startTimeText->GetPosition().x + startTimeText->GetSize().x + 10, 10 + titleCtrl->GetSize().y + 10 + descriptionCtrl->GetSize().y + 10), wxSize(-1, -1), wxSP_ARROW_KEYS, 0, 23);
    startMinute = new wxSpinCtrl(panel, wxID_ANY, "0", wxPoint(startHour->GetPosition().x + startHour->GetSize().x + 10, 10 + titleCtrl->GetSize().y + 10 + descriptionCtrl->GetSize().y + 10), wxSize(-1, -1), wxSP_ARROW_KEYS, 0, 59);

    wxStaticText* endTimeText = new wxStaticText(panel, wxID_ANY, "End time [hr/min] ", wxPoint(10, 10 + titleCtrl->GetSize().y + 10 + descriptionCtrl->GetSize().y + 10 + startTimeText->GetSize().y + 20));
    endHour = new wxSpinCtrl(panel, wxID_ANY, "0", wxPoint(endTimeText->GetPosition().x + endTimeText->GetSize().x + 10, startMinute->GetPosition().y + startMinute->GetSize().y + 10), wxSize(-1, -1), wxSP_ARROW_KEYS, 0, 23);
    endMinute = new wxSpinCtrl(panel, wxID_ANY, "0", wxPoint(startHour->GetPosition().x + startHour->GetSize().x + 10, startMinute->GetPosition().y + startMinute->GetSize().y + 10), wxSize(-1, -1), wxSP_ARROW_KEYS, 0, 59);

    wxButton* addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(10, titleCtrl->GetSize().y + 10 + descriptionCtrl->GetSize().y + 10 + startTimeText->GetSize().y + 20 + endTimeText->GetSize().y + 20), wxSize(100, 30));
    wxButton* closeButton = new wxButton(panel, wxID_ANY, "Close", wxPoint(10 + addButton->GetSize().x + 10, titleCtrl->GetSize().y + 10 + descriptionCtrl->GetSize().y + 10 + startTimeText->GetSize().y + 20 + endTimeText->GetSize().y + 20), wxSize(100, 30));

    closeButton->Bind(wxEVT_BUTTON, &DialogAddActivity::OnCloseButtonClicked, this);
    addButton->Bind(wxEVT_BUTTON, &DialogAddActivity::OnAddButtonClicked, this);
}

void DialogAddActivity::OnCloseButtonClicked(wxCommandEvent &event) {
    Close();
}

void DialogAddActivity::OnAddButtonClicked(wxCommandEvent &event) {
    std::string title = titleCtrl->GetValue().ToStdString();
    std::string description = descriptionCtrl->GetValue().ToStdString();
    int startHour = this->startHour->GetValue();
    int startMinute = this->startMinute->GetValue();
    int endHour = this->endHour->GetValue();
    int endMinute = this->endMinute->GetValue();

    if (title.empty() || description.empty()) {
        wxMessageBox("Title and description cannot be empty", "Error", wxICON_ERROR);
    } else if (startHour > endHour || (startHour == endHour && startMinute > endMinute)) {
        wxMessageBox("Start time cannot be after end time", "Error", wxICON_ERROR);
    } else {
        Time startTime = Time(startHour, startMinute, 0);
        Time endTime = Time(endHour, endMinute, 0);
        Activity activity = Activity(title, description, startTime, endTime);


        if (mainFrame->addActivityToDay(day.ToStdString(), activity)) {
            Close();
        } else {
            wxMessageBox("There is already an activity with that title", "Error", wxICON_ERROR);
        }
    }

}
