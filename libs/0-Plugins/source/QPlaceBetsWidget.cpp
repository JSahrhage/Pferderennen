// Project Includes
#include "QPlaceBetsWidget.h"
#include "AssetConfig.h"
#include "MagicEnum.h"

QPlaceBetsWidget::QPlaceBetsWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent) : m_model(model), m_assetConfig(assetConfig)
{
    generateGeneralLayout();
    connects();
}

QPlaceBetsWidget::~QPlaceBetsWidget()
{

}

void QPlaceBetsWidget::connects()
{
#pragma warning(disable:26444)
    connect(this->m_chooseGameModePushButton, &QPushButton::clicked, this, &QPlaceBetsWidget::chooseGameModeButtonClicked);
    connect(this->m_enterPlayerPushButton, &QPushButton::clicked, this, &QPlaceBetsWidget::enterPlayerButtonClicked);
    connect(this->m_proceedPushButton, &QPushButton::clicked, this, &QPlaceBetsWidget::proceedButtonClicked);
}

void QPlaceBetsWidget::setController(std::shared_ptr<IController> controller)
{
    this->m_controller = controller;
}

void QPlaceBetsWidget::generateGeneralLayout()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QPixmap logoLabelPixmap(QString::fromStdString(pathToAssets + "/placeBetsAssets/Logo.png"));
    logoLabelPixmap = logoLabelPixmap.scaled(m_logoLabel->size() / 2);
    m_logoLabel->setPixmap(logoLabelPixmap);

    QPixmap chooseGameModePushButtonPixmap(QString::fromStdString(pathToAssets + "/placeBetsAssets/ChooseGameModeButtonIcon.png"));
    QIcon chooseGameModePushButtonIcon(chooseGameModePushButtonPixmap);
    m_chooseGameModePushButton->setIcon(chooseGameModePushButtonIcon);
    m_chooseGameModePushButton->setIconSize(QSize(256, 48));

    QPixmap enterPlayerPushButtonPixmap(QString::fromStdString(pathToAssets + "/placeBetsAssets/EnterPlayerButtonIcon.png"));
    QIcon enterPlayerPushButtonIcon(enterPlayerPushButtonPixmap);
    m_enterPlayerPushButton->setIcon(enterPlayerPushButtonIcon);
    m_enterPlayerPushButton->setIconSize(QSize(256, 48));

    QPixmap proceedPushButtonPixmap(QString::fromStdString(pathToAssets + "/placeBetsAssets/ProceedButtonIcon.png"));
    QIcon proceedPushButtonIcon(proceedPushButtonPixmap);
    m_proceedPushButton->setIcon(proceedPushButtonIcon);
    m_proceedPushButton->setIconSize(QSize(256, 48));

    m_playersWidgetTopWidget->setLayout(m_playersWidgetTopWidgetLayout);

    m_pushButtonsWidgetLayout->addWidget(m_chooseGameModePushButton, Qt::AlignCenter);
    m_pushButtonsWidgetLayout->addWidget(m_enterPlayerPushButton, Qt::AlignCenter);
    m_pushButtonsWidgetLayout->addWidget(m_proceedPushButton, Qt::AlignCenter);

    m_pushButtonsWidget->setLayout(m_pushButtonsWidgetLayout);

    m_playersWidgetMainLayout->addWidget(m_playersWidgetTopWidget, Qt::AlignCenter);
    m_playersWidgetMainLayout->addWidget(m_pushButtonsWidget, Qt::AlignCenter);

    m_playersWidget->setFixedSize(QSize(1024, 640));
    m_playersWidget->setLayout(m_playersWidgetMainLayout);

    m_mainLayout->addWidget(m_logoLabel, 12, Qt::AlignCenter);
    m_mainLayout->addWidget(m_playersWidget, 14, Qt::AlignCenter);

    this->setLayout(m_mainLayout);
}

void QPlaceBetsWidget::updateUI()
{
    this->addBetRows();
}

void QPlaceBetsWidget::addBetRows()
{
    this->m_betRows.clear();

    if (m_playersWidgetTopWidgetLayout != nullptr)
    {
        QLayoutItem* item;
        while ((item = m_playersWidgetTopWidgetLayout->takeAt(0)) != nullptr)
        {
            delete item->widget();
            delete item;
        }
    }

    for (auto& player : this->m_model->getPlayer())
    {
        QWidget* widget = new QWidget;
        QHBoxLayout* layout = new QHBoxLayout;

        QLabel* label = new QLabel;
        QComboBox* comboBox = new QComboBox;
        QSpinBox* spinBox = new QSpinBox;

        std::string playerName = player.getName();

        label->setText(QString::fromStdString(playerName));
        label->setStyleSheet("color: white");
        label->setAlignment(Qt::AlignCenter);

        comboBox->setEditable(true);
        comboBox->lineEdit()->setReadOnly(true);
        comboBox->lineEdit()->setAlignment(Qt::AlignCenter);

        for (const auto& suit : Card::SuitConstants::AllSuits)
        {
            comboBox->addItem(QString::fromStdString(static_cast<std::string>(magic_enum::enum_name(suit))));
        }

        comboBox->setStyleSheet("color: white");
        for (int i = 0; i < comboBox->count(); ++i)
        {
            comboBox->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
        }

        spinBox->setValue(0);
        spinBox->setStyleSheet("color: white");
        spinBox->setAlignment(Qt::AlignCenter);

        layout->addWidget(label, Qt::AlignCenter);
        layout->addWidget(comboBox, Qt::AlignCenter);
        layout->addWidget(spinBox, Qt::AlignCenter);

        widget->setLayout(layout);

        this->m_betRows.push_back(std::make_tuple(playerName, comboBox, spinBox));

        m_playersWidgetTopWidgetLayout->addWidget(widget, Qt::AlignCenter);
    }
}

void QPlaceBetsWidget::chooseGameModeButtonClicked()
{
    m_controller->placeBetsChooseGameModeButtonClicked();
}

void QPlaceBetsWidget::enterPlayerButtonClicked()
{
    m_controller->placeBetsEnterPlayerButtonClicked();
}

void QPlaceBetsWidget::proceedButtonClicked()
{
    std::vector<std::tuple<std::string, std::string, int>> bets;
    for (const auto& betRow : this->m_betRows)
    {
        bets.push_back(std::make_tuple(std::get<0>(betRow), std::get<1>(betRow)->currentText().toStdString(), std::get<2>(betRow)->value()));
    }

    m_controller->placeBetsProceedButtonClicked(bets);
}
