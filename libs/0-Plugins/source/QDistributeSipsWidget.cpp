// Project Includes
#include "QDistributeSipsWidget.h"
#include "AssetConfig.h"

QDistributeSipsWidget::QDistributeSipsWidget(std::shared_ptr<Model> model, std::shared_ptr<IConfig> assetConfig, QWidget* parent) : m_model(model), m_assetConfig(assetConfig)
{
    generateGeneralLayout();
    connects();
}

QDistributeSipsWidget::~QDistributeSipsWidget()
{

}

void QDistributeSipsWidget::connects()
{
#pragma warning(disable:26444)
    connect(this->m_proceedPushButton, &QPushButton::clicked, this, &QDistributeSipsWidget::proceedButtonClicked);
}

void QDistributeSipsWidget::setController(IController* controller)
{
    this->m_controller = controller;
}

void QDistributeSipsWidget::generateGeneralLayout()
{
    std::string pathToAssets = std::dynamic_pointer_cast<AssetConfig>(this->m_assetConfig)->getPathToAssets();

    QPixmap logoLabelPixmap(QString::fromStdString(pathToAssets + "/distributeSipsAssets/Logo.png"));
    logoLabelPixmap = logoLabelPixmap.scaled(m_logoLabel->size());
    m_logoLabel->setPixmap(logoLabelPixmap);

    QPixmap addNewPlayerRowPushButtonPixmap(QString::fromStdString(pathToAssets + "/distributeSipsAssets/ProceedButtonIcon.png"));
    QIcon addNewPlayerRowPushButtonIcon(addNewPlayerRowPushButtonPixmap);
    m_proceedPushButton->setIcon(addNewPlayerRowPushButtonIcon);
    m_proceedPushButton->setIconSize(QSize(256, 48));
    m_proceedPushButton->setEnabled(false);

    m_playersWidgetTopWidget->setLayout(m_playersWidgetTopWidgetLayout);

    m_playersWidgetMainLayout->addWidget(m_playersWidgetTopWidget, Qt::AlignCenter);
    m_playersWidgetMainLayout->addWidget(m_proceedPushButton, Qt::AlignCenter);

    m_playersWidget->setFixedSize(QSize(1024, 448));
    m_playersWidget->setLayout(m_playersWidgetMainLayout);

    m_mainLayout->addWidget(m_logoLabel, 12, Qt::AlignCenter);
    m_mainLayout->addWidget(m_playersWidget, 14, Qt::AlignCenter);

    this->setLayout(m_mainLayout);
}

void QDistributeSipsWidget::updateUI()
{
    this->addDistributionRows();
}

void QDistributeSipsWidget::addDistributionRows()
{
    this->m_distributionRows.clear();

    if (m_playersWidgetTopWidgetLayout != nullptr)
    {
        QLayoutItem* item;
        while ((item = m_playersWidgetTopWidgetLayout->takeAt(0)) != nullptr)
        {
            delete item->widget();
            delete item;
        }
    }

    if (m_model->getVictoriousBets().empty())
    {
        this->m_proceedPushButton->setEnabled(true);
        return;
    }

    std::vector<Player> allPlayer = m_model->getPlayer();
    for (Bet& victoriousBet : m_model->getVictoriousBets())
    {
        Player victoriousPlayer = victoriousBet.getPlayer();

        QLabel* sipsToDistributeLeftLabel = new QLabel;
        sipsToDistributeLeftLabel->setText(QString::fromStdString(std::to_string(victoriousBet.getSips())));
        sipsToDistributeLeftLabel->setStyleSheet("color: white");
        sipsToDistributeLeftLabel->setAlignment(Qt::AlignCenter);

        std::vector<std::pair<Player, QSpinBox*>> distributedSips;
        for (const Player& player : allPlayer)
        {
            QSpinBox* spinBox = new QSpinBox;

#pragma warning(disable:26444)
            connect(spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &QDistributeSipsWidget::updateSipsToDistributeLeftLabel);

            spinBox->setMinimum(0);
            spinBox->setMaximum(victoriousBet.getSips());
            spinBox->setStyleSheet("color: white");
            spinBox->setAlignment(Qt::AlignCenter);

            if (victoriousPlayer == player)
            {
                spinBox->setEnabled(false);
            }

            distributedSips.push_back(std::make_pair(player, spinBox));
        }

        m_distributionRows.push_back(DistributionRow(victoriousPlayer, sipsToDistributeLeftLabel, distributedSips));
    }

    int column = 1;
    for (Player& player : allPlayer)
    {
        QLabel* playerLabel = new QLabel;
        playerLabel->setText(QString::fromStdString(player.getName()));
        playerLabel->setStyleSheet("color: white");
        playerLabel->setAlignment(Qt::AlignCenter);
        m_playersWidgetTopWidgetLayout->addWidget(playerLabel, 0, column);
        column++;
    }

    int row = 1;
    for (DistributionRow& distributionRow : this->m_distributionRows)
    {
        QLabel* victoriousPlayerLabel = new QLabel;
        victoriousPlayerLabel->setText(QString::fromStdString(distributionRow.getDistributingPlayer().getName()));
        victoriousPlayerLabel->setStyleSheet("color: white");
        victoriousPlayerLabel->setAlignment(Qt::AlignCenter);
        m_playersWidgetTopWidgetLayout->addWidget(victoriousPlayerLabel, row, 0);

        int spinBoxColumn = 1;
        for (const auto& [player, spinBox] : distributionRow.getDistributedSips())
        {
            m_playersWidgetTopWidgetLayout->addWidget(spinBox, row, spinBoxColumn);
            spinBoxColumn++;
        }
        m_playersWidgetTopWidgetLayout->addWidget(distributionRow.getSipsToDistributeLeftLabel(), row, spinBoxColumn);

        row++;
    }
}

void QDistributeSipsWidget::updateSipsToDistributeLeftLabel()
{
    for (DistributionRow& distributionRow : this->m_distributionRows)
    {
        for (const auto& [player, spinBox] : distributionRow.getDistributedSips())
        {
            if (spinBox == sender())
            {
                int distributedSips = 0;
                for (const auto& [player, spinBox] : distributionRow.getDistributedSips())
                {
                    distributedSips += spinBox->value();
                }
                
                int totalSipsToDistribute = 0;
                for (Bet& victoriousBet : m_model->getVictoriousBets())
                {
                    if (victoriousBet.getPlayer() == distributionRow.getDistributingPlayer())
                    {
                        totalSipsToDistribute = victoriousBet.getSips();
                    }
                }

                int sipsToDistributeLeft = totalSipsToDistribute - distributedSips;

                QLabel* sipsToDistributeLeftLabel = distributionRow.getSipsToDistributeLeftLabel();
                if (sipsToDistributeLeft > 0)
                {
                    distributionRow.setAreSipsDistributed(false);
                    sipsToDistributeLeftLabel->setStyleSheet("color: white");
                }
                else if (sipsToDistributeLeft == 0)
                {
                    distributionRow.setAreSipsDistributed(true);
                    sipsToDistributeLeftLabel->setStyleSheet("color: green");
                }
                else if (sipsToDistributeLeft < 0)
                {
                    distributionRow.setAreSipsDistributed(false);
                    sipsToDistributeLeftLabel->setStyleSheet("color: red");
                }

                sipsToDistributeLeftLabel->setText(QString::fromStdString(std::to_string(sipsToDistributeLeft) + " sips left"));
            }
        }
    }

    this->checkAllSipsDistributed();
}

void QDistributeSipsWidget::checkAllSipsDistributed()
{
    bool allSipsDistributed = true;
    for (DistributionRow& distributionRow : this->m_distributionRows)
    {
        if (!distributionRow.getAreSipsDistributed())
        {
            allSipsDistributed = false;
        }
    }

    this->m_proceedPushButton->setEnabled(allSipsDistributed);
}

void QDistributeSipsWidget::proceedButtonClicked()
{
    this->m_controller->distributeSipsProceedButtonClicked();
}
