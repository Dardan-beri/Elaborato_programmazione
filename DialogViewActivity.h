//
// Created by Dardan Matias Berisha on 08/07/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_DIALOGVIEWACTIVITY_H
#define ELABORATO_PROGRAMMAZIONE_DIALOGVIEWACTIVITY_H


#include <wx/wx.h>
#include "MainFrame.h"

class DialogViewActivity : public wxDialog{
public:
    explicit DialogViewActivity(wxString title, MainFrame* mainFrame, Activity activity, wxString day);
private:
    MainFrame* mainFrame;
    Activity activity;
    wxString day;

    void OnCloseButtonClicked(wxCommandEvent& event);
    void OnDeleteButtonClicked(wxCommandEvent& event);
};


#endif //ELABORATO_PROGRAMMAZIONE_DIALOGVIEWACTIVITY_H
