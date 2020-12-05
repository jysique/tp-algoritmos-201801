#pragma once
#include "CEscenario.h"
#include "CBird.h"
namespace TFAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormFlappyBird
	/// </summary>
	public ref class FormFlappyBird : public System::Windows::Forms::Form
	{
	public:
		FormFlappyBird(void)
		{
			InitializeComponent();
			this->escenario = new CEscenario();
			gr = this->CreateGraphics();
			this->bmp_fondo = gcnew Bitmap("fondo1.png");
			this->ancho_fondo = bmp_fondo->Width;
			this->alto_fondo = bmp_fondo->Height;
			a_visible_fondo = Rectangle(0, 0, ancho_fondo, alto_fondo);
		}
	private:
		Graphics ^ gr;
		BufferedGraphics^buffer;
		BufferedGraphicsContext^espacio;

		//FONDO
		CEscenario* escenario;
		Bitmap^bmp_fondo;
		Rectangle a_visible_fondo;
		int ancho_fondo;
		int alto_fondo;

		//Jugador
		

	private: System::Windows::Forms::Timer^  timer1;
			 

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormFlappyBird()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormFlappyBird::timer1_Tick);
			// 
			// FormFlappyBird
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(360, 560);
			this->Name = L"FormFlappyBird";
			this->Text = L"FormFlappyBird";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		espacio = BufferedGraphicsManager::Current;
		buffer = espacio->Allocate(gr, this->ClientRectangle);
		buffer->Graphics->Clear(System::Drawing::Color::White);

		//escenario->dibujar_escenario(buffer->Graphics, bmp_fondo, a_visible_fondo);

		buffer->Render(gr);
	}
	};
}
