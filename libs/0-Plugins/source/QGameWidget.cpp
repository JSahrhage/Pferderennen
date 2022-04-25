// Project Includes
#include "QGameWidget.h"
#include "AssetConfig.h"
#include "SizeConfig.h"

QGameWidget::QGameWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, std::shared_ptr<IConfig> sizeConfig, QWidget* parent) : m_model(model), m_assetConfig(assetConfig), m_sizeConfig(sizeConfig)
{
    generateGeneralLayout();
    connects();
}

QGameWidget::~QGameWidget()
{

}

void QGameWidget::connects()
{
#pragma warning(disable:26444)
    connect(this->m_drawPushButton, &QPushButton::clicked, this, &QGameWidget::drawButtonClicked);
    connect(this->m_proceedPushButton, &QPushButton::clicked, this, &QGameWidget::proceedButtonClicked);
}

void QGameWidget::setController(IController* controller)
{
    this->m_controller = controller;
}

void QGameWidget::generateGeneralLayout()
{
    QVBoxLayout* mainLayout = new QVBoxLayout;

    QWidget* topWidget = new QWidget;
    QHBoxLayout* topLayout = new QHBoxLayout;

    topLayout->addWidget(this->m_playground, 4);
    topLayout->addWidget(this->m_deck, 1);
    topWidget->setLayout(topLayout);

    QWidget* bottomWidget = new QWidget;
    QHBoxLayout* bottomLayout = new QHBoxLayout;

    bottomLayout->addWidget(this->m_hurdles, 4);
    bottomLayout->addWidget(this->m_proceedButtonWidget, 1);
    bottomWidget->setLayout(bottomLayout);

    mainLayout->addWidget(topWidget, 4);
    mainLayout->addWidget(bottomWidget, 1);

    this->setLayout(mainLayout);

    setUpPlayground();
    setUpDeck();
    setUpHurdles();
    setUpProceedButton();
}

void QGameWidget::setUpPlayground()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();
    int cardWidth = std::dynamic_pointer_cast<SizeConfig>(this->m_sizeConfig)->getCardWidth();
    int cardHeight = std::dynamic_pointer_cast<SizeConfig>(this->m_sizeConfig)->getCardHeight();

    QVBoxLayout* playgroundLayout = new QVBoxLayout;

    QWidget* diamondWidget = new QWidget;
    QWidget* heartWidget = new QWidget;
    QWidget* spadeWidget = new QWidget;
    QWidget* clubWidget = new QWidget;

    QMatrix rm;
    rm.rotate(90);

    for (int position = 0; position < 7; position++)
    {
        QLabel* label = new QLabel;
        label->setFixedSize(cardWidth, cardHeight);
        this->m_diamondLayout->addWidget(label);
        this->m_diamondLabels.insert(this->m_diamondLabels.begin(), label);
    }

    QImage diamondImage(QString::fromStdString(pathToAssets + "/cards/AD.png"));
    QPixmap diamondPixmap = QPixmap::fromImage(diamondImage);
    diamondPixmap = diamondPixmap.transformed(rm);
    m_diamondLabels.at(0)->setPixmap(diamondPixmap);
    m_diamondLabels.at(0)->setScaledContents(true);

    for (int position = 0; position < 7; position++)
    {
        QLabel* label = new QLabel;
        label->setFixedSize(cardWidth, cardHeight);
        this->m_heartLayout->addWidget(label);
        this->m_heartLabels.insert(this->m_heartLabels.begin(), label);
    }

    QImage heartImage(QString::fromStdString(pathToAssets + "/cards/AH.png"));
    QPixmap heartPixmap = QPixmap::fromImage(heartImage);
    heartPixmap = heartPixmap.transformed(rm);
    m_heartLabels.at(0)->setPixmap(heartPixmap);
    m_heartLabels.at(0)->setScaledContents(true);

    for (int position = 0; position < 7; position++)
    {
        QLabel* label = new QLabel;
        label->setFixedSize(cardWidth, cardHeight);
        this->m_spadeLayout->addWidget(label);
        this->m_spadeLabels.insert(this->m_spadeLabels.begin(), label);
    }

    QImage spadeImage(QString::fromStdString(pathToAssets + "/cards/AS.png"));
    QPixmap spadePixmap = QPixmap::fromImage(spadeImage);
    spadePixmap = spadePixmap.transformed(rm);
    m_spadeLabels.at(0)->setPixmap(spadePixmap);
    m_spadeLabels.at(0)->setScaledContents(true);

    for (int position = 0; position < 7; position++)
    {
        QLabel* label = new QLabel;
        label->setFixedSize(cardWidth, cardHeight);
        this->m_clubLayout->addWidget(label);
        this->m_clubLabels.insert(this->m_clubLabels.begin(), label);
    }

    QImage clubImage(QString::fromStdString(pathToAssets + "/cards/AC.png"));
    QPixmap clubPixmap = QPixmap::fromImage(clubImage);
    clubPixmap = clubPixmap.transformed(rm);
    m_clubLabels.at(0)->setPixmap(clubPixmap);
    m_clubLabels.at(0)->setScaledContents(true);

    diamondWidget->setLayout(this->m_diamondLayout);
    heartWidget->setLayout(this->m_heartLayout);
    spadeWidget->setLayout(this->m_spadeLayout);
    clubWidget->setLayout(this->m_clubLayout);

    playgroundLayout->addWidget(diamondWidget);
    playgroundLayout->addWidget(heartWidget);
    playgroundLayout->addWidget(spadeWidget);
    playgroundLayout->addWidget(clubWidget);

    this->m_playground->setLayout(playgroundLayout);
}

void QGameWidget::setUpDeck()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();
    int cardWidth = std::dynamic_pointer_cast<SizeConfig>(this->m_sizeConfig)->getCardWidth();
    int cardHeight = std::dynamic_pointer_cast<SizeConfig>(this->m_sizeConfig)->getCardHeight();

    QVBoxLayout* deckLayout = new QVBoxLayout;

    deckLayout->setAlignment(Qt::AlignHCenter);

    QPixmap drawPushButtonPixmap(QString::fromStdString(pathToAssets + "/gameAssets/DrawCardButtonIcon.png"));
    QIcon drawPushButtonIcon(drawPushButtonPixmap);
    this->m_drawPushButton->setIcon(drawPushButtonIcon);
    this->m_drawPushButton->setIconSize(QSize(192, 96));

    QImage image(QString::fromStdString(pathToAssets + "/cards/0.png"));
    QMatrix rm;
    rm.rotate(90);
    QPixmap pixmap = QPixmap::fromImage(image);
    pixmap = pixmap.transformed(rm);
    this->m_closedCardLabel->setFixedSize(cardWidth, cardHeight);
    this->m_closedCardLabel->setPixmap(pixmap);
    this->m_closedCardLabel->setScaledContents(true);

    this->m_openedCardLabel->setFixedSize(cardWidth, cardHeight);

    deckLayout->addWidget(this->m_drawPushButton);
    deckLayout->addWidget(this->m_closedCardLabel);
    deckLayout->addWidget(this->m_openedCardLabel);

    this->m_deck->setLayout(deckLayout);
}

void QGameWidget::setUpHurdles()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();
    int cardWidth = std::dynamic_pointer_cast<SizeConfig>(this->m_sizeConfig)->getCardWidth();
    int cardHeight = std::dynamic_pointer_cast<SizeConfig>(this->m_sizeConfig)->getCardHeight();

    QWidget* innerHurdlesWidget = new QWidget;
    QHBoxLayout* innerHurdlesLayout = new QHBoxLayout;

    QLabel* leftPlaceholder = new QLabel;
    leftPlaceholder->setFixedSize(cardWidth, cardHeight);
    innerHurdlesLayout->addWidget(leftPlaceholder);

    for (int position = 0; position < 5; position++)
    {
        QLabel* label = new QLabel;
        QImage image(QString::fromStdString(pathToAssets + "/cards/0.png"));
        QMatrix rm;
        rm.rotate(90);
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.transformed(rm);
        label->setFixedSize(cardWidth, cardHeight);
        label->setPixmap(pixmap);
        label->setScaledContents(true);
        this->m_hurdleLabels.insert(this->m_hurdleLabels.begin(), label);

        innerHurdlesLayout->addWidget(label);
    }

    QLabel* rightPlaceholder = new QLabel;
    rightPlaceholder->setFixedSize(cardWidth, cardHeight);
    innerHurdlesLayout->addWidget(rightPlaceholder);

    innerHurdlesWidget->setLayout(innerHurdlesLayout);
    this->m_hurdlesLayout->addWidget(innerHurdlesWidget);

    this->m_hurdles->setLayout(this->m_hurdlesLayout);
}

void QGameWidget::setUpProceedButton()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QHBoxLayout* proceedButtonLayout = new QHBoxLayout;

    QPixmap proceedPushButtonPixmap(QString::fromStdString(pathToAssets + "/gameAssets/ProceedButtonIcon.png"));
    QIcon proceedPushButtonIcon(proceedPushButtonPixmap);
    this->m_proceedPushButton->setIcon(proceedPushButtonIcon);
    this->m_proceedPushButton->setIconSize(QSize(256, 48));
    this->m_proceedPushButton->setEnabled(false);

    proceedButtonLayout->addWidget(this->m_proceedPushButton);

    this->m_proceedButtonWidget->setLayout(proceedButtonLayout);
}

void QGameWidget::updateUI()
{
    updatePlayground();
    updateDeck();
    updateHurdles();
    updateProceedButton();
}

void QGameWidget::updatePlayground()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QMatrix rm;
    rm.rotate(90);

    for (QLabel* label : this->m_diamondLabels)
    {
        label->clear();
    }

    int diamondPosition = this->m_model->getDiamondPosition();
    QImage diamondImage(QString::fromStdString(pathToAssets + "/cards/AD.png"));
    QPixmap diamondPixmap = QPixmap::fromImage(diamondImage);
    diamondPixmap = diamondPixmap.transformed(rm);
    this->m_diamondLabels.at(diamondPosition)->setPixmap(diamondPixmap);
    this->m_diamondLabels.at(diamondPosition)->setScaledContents(true);

    for (QLabel* label : this->m_heartLabels)
    {
        label->clear();
    }

    int heartPosition = this->m_model->getHeartPosition();
    QImage heartImage(QString::fromStdString(pathToAssets + "/cards/AH.png"));
    QPixmap heartPixmap = QPixmap::fromImage(heartImage);
    heartPixmap = heartPixmap.transformed(rm);
    this->m_heartLabels.at(heartPosition)->setPixmap(heartPixmap);
    this->m_heartLabels.at(heartPosition)->setScaledContents(true);

    for (QLabel* label : this->m_spadeLabels)
    {
        label->clear();
    }

    int spadePosition = this->m_model->getSpadePosition();
    QImage spadeImage(QString::fromStdString(pathToAssets + "/cards/AS.png"));
    QPixmap spadePixmap = QPixmap::fromImage(spadeImage);
    spadePixmap = spadePixmap.transformed(rm);
    this->m_spadeLabels.at(spadePosition)->setPixmap(spadePixmap);
    this->m_spadeLabels.at(spadePosition)->setScaledContents(true);

    for (QLabel* label : this->m_clubLabels)
    {
        label->clear();
    }

    int clubPosition = this->m_model->getClubPosition();
    QImage clubImage(QString::fromStdString(pathToAssets + "/cards/AC.png"));
    QPixmap clubPixmap = QPixmap::fromImage(clubImage);
    clubPixmap = clubPixmap.transformed(rm);
    this->m_clubLabels.at(clubPosition)->setPixmap(clubPixmap);
    this->m_clubLabels.at(clubPosition)->setScaledContents(true);
}

void QGameWidget::updateDeck()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    this->m_openedCardLabel->clear();

    if (this->m_model->getFirstCardDrawn())
    {
        QMatrix rm;
        rm.rotate(90);
        QImage openedCardImage(QString::fromStdString(pathToAssets + "/cards/" + this->m_model->getLastDrawnCard().getAcronym() + ".png"));
        QPixmap openedCardPixmap = QPixmap::fromImage(openedCardImage);
        openedCardPixmap = openedCardPixmap.transformed(rm);

        this->m_openedCardLabel->setPixmap(openedCardPixmap);
        this->m_openedCardLabel->setScaledContents(true);
    }
}

void QGameWidget::updateHurdles()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QMatrix rm;
    rm.rotate(90);

    short index = 0;
    for (auto& [card, isRevealed] : this->m_model->getHurdles())
    {
        if (isRevealed)
        {
            QImage reveleadHurdleImage(QString::fromStdString(pathToAssets + "/cards/" + card.getAcronym() + ".png"));
            QPixmap reveleadHurdlePixmap = QPixmap::fromImage(reveleadHurdleImage);

            reveleadHurdlePixmap = reveleadHurdlePixmap.transformed(rm);
            this->m_hurdleLabels.at(index)->setPixmap(reveleadHurdlePixmap);
            this->m_hurdleLabels.at(index)->setScaledContents(true);
        }
        else
        {
            QImage coveredhurdleImage(QString::fromStdString(pathToAssets + "/cards/0.png"));
            QPixmap covereredhurdlePixmap = QPixmap::fromImage(coveredhurdleImage);

            covereredhurdlePixmap = covereredhurdlePixmap.transformed(rm);
            this->m_hurdleLabels.at(index)->setPixmap(covereredhurdlePixmap);
            this->m_hurdleLabels.at(index)->setScaledContents(true);
        }
        index++;
    }
}

void QGameWidget::updateProceedButton()
{
    this->m_drawPushButton->setEnabled(m_model->getGameDrawButtonActive());
    this->m_proceedPushButton->setEnabled(m_model->getGameProceedButtonActive());
}

void QGameWidget::drawButtonClicked()
{
    m_controller->gameDrawButtonClicked();
}

void QGameWidget::proceedButtonClicked()
{
    m_controller->gameProceedButtonClicked();
}
