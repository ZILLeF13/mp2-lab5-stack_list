#include "MyForm.h"

#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Culculator::MyForm form;
    Application::Run(% form);
}
