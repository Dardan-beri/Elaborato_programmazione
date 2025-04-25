//
// Created by Dardan Matias Berisha on 05/07/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_MAINFRAME_H
#define ELABORATO_PROGRAMMAZIONE_MAINFRAME_H


#include <wx/wx.h>
#include "ActivityLog.h"
#include <map>

class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString& title);
    bool addDay(const std::string day);
    bool addActivityToDay(const std::string day, const Activity& activity);
    bool removeActivityFromDay(const std::string &day, std::basic_string<char, std::char_traits<char>, std::allocator<char>> title);

private:
    std::map<std::string, ActivityLog> days;
    wxListBox* sideListBox;
    wxListBox* mainListBox;
    wxString lastSelectedDay;

    void OnAddButtonClick(wxCommandEvent& event);
    void OnSideListBoxClicked(wxCommandEvent& event);
    void OnMainListBoxClicked(wxCommandEvent& event);
    void OnActivityButtonClick(wxCommandEvent& event);
};


#endif //ELABORATO_PROGRAMMAZIONE_MAINFRAME_H
