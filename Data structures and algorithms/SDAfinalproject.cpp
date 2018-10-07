#include "SDAfinalproject.h"

SDAfinalproject::SDAfinalproject(QWidget *parent, string file)
	: QMainWindow(parent), fileName{ file }
{
	ui.setupUi(this);
	readFromFile();
    populateList();
	QObject::connect(ui.addButton, &QPushButton::clicked, this, [this]() { addButtonEventHandler();	});
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, [this]() { removeButtonEventHandler();	});
	QObject::connect(ui.searchButton, &QPushButton::clicked, this, [this]() { searchButtonEventHandler();	});

}


void SDAfinalproject::readFromFile()
{
	ifstream file(this->fileName);
	int capacity;
	file >> capacity;
	//assert(capacity == 5);
	multiMap = new MultiMap{ capacity };
	int key, value;
	while(file >> key >> value)
		multiMap->add(new TElem{ key, value });
	/*assert(multiMap->element(1)->getValue() == 203);
	assert(multiMap->element(3)->getValue() == 203);*/
	file.close();
	
}

void SDAfinalproject::populateList()
{
	ui.multiMapElementsListWidget->clear();
	MultiMap::Iterator it(*multiMap);

	while(it.valid())
	{
		
		ui.multiMapElementsListWidget->addItem((to_string(it.getCurrent()->getKey()) + " "
			+
			to_string(it.getCurrent()->getValue())).c_str());
		it.next();
	}
	//while (it.valid())
	//{
	//	ui.multiMapElementsListWidget->addItem((to_string(it.getCurrent()->getKey()) + " "
	//		+
	//		to_string(it.getCurrent()->getValue())).c_str());
	//		/*ui.multiMapElementsListWidget->addItem((to_string(it.getCurrentPosition())+":  "
	//													+
	//												to_string(it.getCurrent()->getKey()) + " "
	//												+ 
	//												to_string(it.getCurrent()->getValue())).c_str());*/
	////	else
	//	//	ui.multiMapElementsListWidget->addItem("~~~~~EMPTY~~~~~");
	//	//	ui.multiMapElementsListWidget->addItem((to_string(it.getCurrentPosition()) + ":  ~~~~~EMPTY~~~~~").c_str());

	//	it.next();
	//}
	it.~Iterator();
	//setNumberOfEmptyPositions();
}

void SDAfinalproject::setNumberOfEmptyPositions()
{
	string x = "Empty positions : ";
	MultiMap::Iterator it(*multiMap);
	int y = 0;
	while (it.valid())
	{
		if (it.getCurrent()->getKey() != -1)
			y++;
		it.next();
	}

	x += to_string(multiMap->getCapacity()-y);
	it.~Iterator();
	ui.emptyPositionsLabel->setText(x.c_str());
}


void SDAfinalproject::addButtonEventHandler()
{

	if (validInsert())
	{
		int key = ui.keyLineEdit->text().toInt();
		int value = ui.valueLineEdit->text().toInt();
		if (multiMap->add(new TElem{ key, value }))
		{
			ui.errorLabel->setText("ITEM ADDED!");
			populateList();
		}
		else
			ui.errorLabel->setText("ITEM ALREADY EXISTS");
	}
	else
		ui.errorLabel->setText("NR OF FREE ELEMENTS IS 0!");
}


void SDAfinalproject::removeButtonEventHandler()
{
	int key = ui.keyLineEdit->text().toInt();
	int value = ui.valueLineEdit->text().toInt();
	if (multiMap->remove(new TElem{ key, value }))
	{
		ui.errorLabel->setText("ITEM REMOVED!");
		populateList();
	}
	else
		ui.errorLabel->setText("ITEM DOES NOT EXIST!");
}

void SDAfinalproject::searchButtonEventHandler()
{
	int key = ui.keyLineEdit->text().toInt();
	int value = ui.valueLineEdit->text().toInt();
	if (multiMap->search(key, value) == 1)
		ui.errorLabel->setText("ITEM EXISTS!");
	else
		ui.errorLabel->setText("ITEM DOES NOT EXIST");
}

int SDAfinalproject::validInsert()
{
	/*MultiMap::Iterator it(*multiMap);
	int y = 0;
	while (it.valid())
	{
		if (it.getCurrent()->getKey() != -1)
			y++;
		it.next();
	}
	it.~Iterator();
	return multiMap->getCapacity() - y;*/
	return 1;
}
