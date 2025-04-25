//
// Created by Dardan Matias Berisha on 07/07/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_DIALOGADDACTIVITY_H
#define ELABORATO_PROGRAMMAZIONE_DIALOGADDACTIVITY_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "MainFrame.h"

class DialogAddActivity : public wxDialog {
public:
    explicit DialogAddActivity(MainFrame* mainFrame, wxString day);
private:
    MainFrame* mainFrame;
    wxString day;

    wxTextCtrl* titleCtrl;
    wxTextCtrl* descriptionCtrl;
    wxSpinCtrl* startHour;
    wxSpinCtrl* startMinute;
    wxSpinCtrl* endHour;
    wxSpinCtrl* endMinute;

    void OnCloseButtonClicked(wxCommandEvent& event);
    void OnAddButtonClicked(wxCommandEvent& event);
};


#endif //ELABORATO_PROGRAMMAZIONE_DIALOGADDACTIVITY_H
