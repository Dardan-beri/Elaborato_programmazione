//
// Created by Dardan Matias Berisha on 06/07/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_DIALOGADDDAY_H
#define ELABORATO_PROGRAMMAZIONE_DIALOGADDDAY_H

#include <wx/wx.h>
#include <wx/osx/dialog.h>
#include <map>
#include "ActivityLog.h"
#include "MainFrame.h"
#include <wx/calctrl.h>

class DialogAddDay : public wxDialog {
public:
    explicit DialogAddDay(const wxString& title, MainFrame* mainFrame);
private:
    void OnAddButtonClicked(wxCommandEvent& event);
    void OnCloseButtonClicked(wxCommandEvent& event);

    MainFrame* mainFrame;

    wxStaticText* text;
    wxTextCtrl* textCtrl;
    wxCalendarCtrl* calendar;
};


#endif //ELABORATO_PROGRAMMAZIONE_DIALOGADDDAY_H
