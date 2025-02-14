#include <Game.hpp>
#include <SFML/Window/Event.hpp>



const float World::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(1200, 800), "World", sf::Style::Close)
	//, landscape()
	//, airplane()
	//, textures()
	//, mTexture()
	//, mPlayer()
	, mWorld(mWindow)
	, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mPlayerAircraft(nullptr)


	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)


	//view Defining
	, mView(mWindow.getDefaultView())
	, mWorldBounds(0.f, 0.f, mView.getSize().x, 4000.f)
	, mSpawnPosition(mView.getSize().x / 2.f, mWorldBounds.height - mView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
{
	//// Prepare the view
	//mView.setCenter(mSpawnPosition);

	//loadTextures();
	//buildScene();

	mFonts.load(FontID::sansation, "Media/Sansation.ttf");

	mStatisticsText.setFont(mFonts.get(FontID::sansation));
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);

	//mWindow.setFramerateLimit(20);

	//mWindow.setVerticalSyncEnabled(true);

	//try
	//{
	//	textures.load(TextureID::Landscape, "Media/Textures/Desert.png");
	//	textures.load(TextureID::Airplane, "Media/Textures/Eagle.png");
	//	fonts.load(FontID::sansation, "Media/Sansation.ttf");
	//}
	//catch (std::runtime_error& e)
	//{
	//	std::cout << "Exception: " << e.what() << std::endl;
	//}
	////Step 1

	//	// Prepare the tiled background
	//sf::Texture& texture = textures.get(TextureID::Landscape);
	//texture.setRepeated(true);
	//landscape.setTexture(texture);
	//landscape.setTextureRect(sf::IntRect(mWorldBounds));

	//airplane.setTexture(textures.get(TextureID::Airplane));
	//airplane.setPosition(200.f, 200.f);

	//mStatisticsText.setFont(mFont);
	//mStatisticsText.setPosition(5.f, 5.f);
	//mStatisticsText.setCharacterSize(10);
	//mStatisticsText.setFillColor(sf::Color::Black);


	//// Access resources
	//sf::Texture& texture1 = textures.get(TextureID::Landscape);
	//landscape.setTexture(texture1);

	//sf::Texture& texture2 = textures.get(TextureID::Airplane);
	//airplane.setTexture(texture2);
	//airplane.setPosition(200.f, 200.f);

	//mStatisticsText.setFont(fonts.get(FontID::sansation));
	//mStatisticsText.setPosition(5.f, 5.f);
	//mStatisticsText.setCharacterSize(10);


	//mBackgroundTexture = textures.get(TextureID::Landscape);
	//mBackgroundTexture.setRepeated(true);
	//landscape.setTexture(mBackgroundTexture);
	//landscape.setTextureRect(sf::IntRect(0, 0, 1200, 800));

	//airplane.setTexture(textures.get(TextureID::Airplane));
	//airplane.setPosition(100.f, 100.f);
	

	//mFont.loadFromFile("Media/Sansation.ttf");
	//mStatisticsText.setFont(mFont);
	//mStatisticsText.setFont(fonts.get(FontID::sansation));
	//mStatisticsText.setPosition(5.f, 5.f);
	//mStatisticsText.setCharacterSize(30);
}
//
//void Game::loadTextures()
//{
//	mTextures.load(TextureID::Eagle, "Media/Textures/Eagle.png");
//	mTextures.load(TextureID::Raptor, "Media/Textures/Raptor.png");
//	mTextures.load(TextureID::Desert, "Media/Textures/Desert.png");
//	mFonts.load(FontID::sansation, "Media/Sansation.ttf");
//}
//void Game::buildScene()
//{
//	// Initialize the different layers
//	for (std::size_t i = 0; i < LayerCount; ++i)
//	{
//		SceneNode::Ptr layer(new SceneNode());
//		mSceneLayers[i] = layer.get();
//
//		mSceneGraph.attachChild(std::move(layer));
//	}
//
//	// Prepare the tiled background
//	sf::Texture& texture = mTextures.get(TextureID::Desert);
//	sf::IntRect textureRect(mWorldBounds);
//	texture.setRepeated(true);
//
//	// Add the background sprite to the scene
//	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
//	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
//	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));
//
//	// Add player's aircraft
//	std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Type::Eagle, mTextures));
//	mPlayerAircraft = leader.get();
//	mPlayerAircraft->setPosition(mSpawnPosition);
//	mPlayerAircraft->setVelocity(40.f, mScrollSpeed);
//	mSceneLayers[Air]->attachChild(std::move(leader));
//
//	// Add two escorting aircrafts, placed relatively to the main plane
//	std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Type::Raptor, mTextures));
//	leftEscort->setPosition(-80.f, 50.f);
//	mPlayerAircraft->attachChild(std::move(leftEscort));
//
//	std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Type::Raptor, mTextures));
//	rightEscort->setPosition(80.f, 50.f);
//	mPlayerAircraft->attachChild(std::move(rightEscort));
//}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		/*switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		}*/

		//switch (event.type)
		//{
		//case sf::Event::KeyPressed:
		//	handlePlayerInput(event.key.code, true);
		//	break;

		//case sf::Event::KeyReleased:
		//	handlePlayerInput(event.key.code, false);
		//	break;

		//case sf::Event::Closed:
		//	mWindow.close();
		//	break;
		//}

		switch (event.type)
		{
		case sf::Event::KeyPressed:
			mWorld.handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			mWorld.handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;

		default:
			break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	//// Scroll the world
	//mView.move(0.f, mScrollSpeed * elapsedTime.asSeconds());

	//sf::Vector2f position = player2.getPosition();
	//sf::Vector2f velocity = player2.getVelocity();

	////velocity.x -= 1.0f;
	////velocity.y -= 0.1f;
	////player2.setVelocity(velocity);
	////// Apply movements
	////player2.update(elapsedTime);

	//player2.setVelocity(0.f, -30.f);
	//// Apply movements
	//player2.update(elapsedTime);

	//sf::Vector2f movement(0.f, 0.f);


	////sf::Vector2f movement(0.f, 0.f);
	////if (mIsMovingUp)
	////	movement.y -= PlayerSpeed;
	////if (mIsMovingDown)
	////	movement.y += PlayerSpeed;
	////if (mIsMovingLeft)
	////	movement.x -= PlayerSpeed;
	////if (mIsMovingRight)
	////	movement.x += PlayerSpeed;

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	//	movement.y -= PlayerSpeed;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//	movement.y += PlayerSpeed;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	//	movement.x -= PlayerSpeed;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	//	movement.x += PlayerSpeed;

	//airplane.move(movement * elapsedTime.asSeconds());

	// Scroll the world
	//mView.move(0.f, mScrollSpeed * dt.asSeconds());

	//// Move the player sidewards (plane scouts follow the main aircraft)
	//sf::Vector2f position = mPlayerAircraft->getPosition();
	//sf::Vector2f velocity = mPlayerAircraft->getVelocity();


	//// If player touches borders, flip its X velocity
	//if (position.x <= mWorldBounds.left + 150.f
	//	|| position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
	//{
	//	velocity.x = -velocity.x;
	//	mPlayerAircraft->setVelocity(velocity);
	//}

	//// Apply movements
	//mSceneGraph.update(dt);

	// Update other world elements
	mWorld.update(elapsedTime);

	
}

void Game::render()
{
	////Step 2
	//mWindow.clear();


	//mWindow.setView(mView);
	//mWindow.draw(landscape);

	//mWindow.setView(mWindow.getDefaultView());
	//mWindow.draw(airplane);
	//mWindow.draw(player.getSprite());
	//mWindow.draw(player2);
	//mWindow.draw(mStatisticsText);

	//mWindow.display();

	//mWindow.clear();
	//mWindow.setView(mView);

	////make sure you remove draw calls to airplane, player, player2
	//mWindow.draw(mSceneGraph);
	//mWindow.setView(mWindow.getDefaultView());

	//mWindow.draw(mStatisticsText);
	//mWindow.display();

	mWindow.clear();
	mWorld.draw();


	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();

}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	//sf::Vector2f position = player2.getPosition();
	//sf::Vector2f velocity = player2.getVelocity();

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		/*mStatisticsText.setString(
			"Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");*/
		mStatisticsText.setString(
			"Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us"
			//+ "\n" +
			//"Position = ( " + std::to_string(position.x) + " , " + std::to_string(position.y) + " )" + "\n" +
			//"Velocity = ( " + std::to_string(velocity.x) + " , " + std::to_string(velocity.y) + " )" + "\n"
		);


		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}