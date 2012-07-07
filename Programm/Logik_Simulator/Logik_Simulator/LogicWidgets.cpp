#pragma once

#include "stdafx.h"

#include "LogicWidgets.h"

using namespace System::Windows::Forms;
using namespace LogicWidgets;

LogicWidget::LogicWidget( String^ type, Point^ location, Gatter^ gate ) {
	this->type = type;
	this->location = location;
	this->gate = gate;

	this->size = gcnew Size(40, 40);
	this->selected = false;
	this->destructed = false;
}

LogicWidget::LogicWidget( ) {
}

void LogicWidget::destruct() {
	this->destructed = true;
	this->inputSignal->destruct();
	this->outputSignal->destruct();
}

Boolean LogicWidget::isDestructed() {
	return this->destructed;
}

void LogicWidget::paint(Graphics^ canvas) {
	if ( !destructed ) {
		Color color;

		if (selected)
		{
			color = Color::Blue;
		} else {
			color = Color::Black;
		}

		Pen^ pen = gcnew Pen(color);
		Font^ font = gcnew Font(FontFamily::GenericMonospace, 10);
		SolidBrush^ sb = gcnew SolidBrush(color);

		canvas->DrawRectangle(pen, location->X, location->Y, this->size->Width, this->size->Height);
		canvas->DrawString(type, font, sb , safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) +3);

	}
}

Size^ LogicWidget::getSize() {
	return this->size;
}

Gatter^ LogicWidget::getGate() {
	return this->gate;
}

Boolean LogicWidget::connectInputSignal(SignalWidget^ sw) {

	if ( this->inputSignal && !( this->inputSignal->isDestructed() ) ) {

		return false;

	} else {

		this->inputSignal = sw;
		return true;

	}

}

void LogicWidget::disconnectInputSignal(SignalWidget^ sw) {
	if (this->inputSignal == sw) {
		this->inputSignal = nullptr;
	}
}

Boolean LogicWidget::connectOutputSignal(SignalWidget^ sw) {

	if (this->outputSignal && !( this->outputSignal->isDestructed() )) {

		return false;

	} else {

		this->outputSignal = sw;
		return true;

	}

}

void LogicWidget::disconnectOutputSignal(SignalWidget^ sw) {
	if (this->outputSignal == sw) {
		this->outputSignal = nullptr;
	}
}

Boolean LogicWidget::widgetHit(Point^ click_location) {
	if ( ( click_location->X >= this->location->X ) && ( click_location->X  <= this->location->X + this->size->Width ) )
	{
		if ( ( click_location->Y >= this->location->Y ) && ( click_location->Y <= this->location->Y  + this->size->Height ) )
		{
			return true;
		}
	}

	return false;
}


SignalWidget::SignalWidget(void) {
	this->destructed = false;
}

SignalWidget::SignalWidget(Signal^ signal) {
	this->destructed = false;
	this->signal = signal;
}

void SignalWidget::destruct() {
	this->destructed = true;
	this->disconnectAll();
	this->signal->setInputGate(nullptr, 0);
	this->signal->addOutputGate(nullptr, 0);
}

Boolean SignalWidget::isDestructed() {
	return this->destructed;
}

void SignalWidget::paint( Graphics^ canvas ) {
	if ( !destructed ) {
		Pen^ pen = gcnew Pen(Color::Black);

		canvas->DrawLine(pen, inputGate->location->X + inputGate->getSize()->Width, inputGate->location->Y + (inputGate->getSize()->Height / 2),
		outputGate->location->X, outputGate->location->Y + ( inputGate->getSize()->Height / 2 ) );
	}
}

Signal^ SignalWidget::getSignal() {
	return this->signal;
}

void SignalWidget::setInputGate(LogicWidget^ lw) {
	this->inputGate = lw;
	Boolean connected = lw->connectOutputSignal(this);

	if ( !connected ) {
		this->destruct();
	} else {
		this->signal->setInputGate(lw->getGate(), 0);
	}
}

void SignalWidget::setOutputGate(LogicWidget^ lw) {
	this->outputGate = lw;
	Boolean connected = lw->connectInputSignal(this);

	if ( !connected ) {
		this->destruct();
	} else {
		this->signal->addOutputGate(lw->getGate(), 0);
	}
}

void SignalWidget::disconnectAll() {
	if (this->inputGate) {
		this->inputGate->disconnectOutputSignal(this);
		this->inputGate = nullptr;
	}
	if (this->outputGate) {
		this->outputGate->disconnectInputSignal(this);
		this->inputGate = nullptr;
	}
}
