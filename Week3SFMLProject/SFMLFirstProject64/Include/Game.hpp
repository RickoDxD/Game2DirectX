#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <World.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include <SceneNode.hpp>
#include <SpriteNode.hpp>
#include <Aircraft.hpp>
#include <array>
#include <iostream>

#include "ResourceIdentifiers.hpp"
#include "Player.hpp"
#include "Player2.hpp"



//namespace Textures
//{
//	enum ID
//	{
//		Landscape,
//		Airplane,
//	};
//}
//
//
//enum class TextureID
//{
//	Landscape,
//	Airplane,
//};
//
//namespace Fonts
//{
//	enum ID
//	{
//		sansation,
//		font2,
//	};
//}
//
//enum class FontID
//{
//	sansation,
//	font2,
//};

class Game : private sf::NonCopyable
{
	public:
								Game();
		void					run();
		

	private:
		void					processEvents();
		void					update(sf::Time elapsedTime);
		void					render();

		void					updateStatistics(sf::Time elapsedTime);	
//		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		

	private:
	
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
		World					mWorld;


		sf::Font				mFont;
		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;


		sf::View							mView;
		sf::FloatRect						mWorldBounds;
		sf::Vector2f						mSpawnPosition;
		float								mScrollSpeed;

		std::size_t				mStatisticsNumFrames;


		/*sf::Texture				mTexture;
		sf::Sprite				mPlayer;*/
	    //TextureHolder			 textures;
		//ResourceHolder<sf::Texture, TextureID> textures;
		//ResourceHolder<sf::Font, FontID> fonts;
		//TextureHolder textures;
		//FontHolder fonts;

		//class Player player;
		//class Player2 player2;



		//sf::Sprite				airplane;
		//sf::Sprite				landscape;
		//sf::Texture             mBackgroundTexture;

		//New Layer

		enum Layer
		{
			Background,
			Air,
			LayerCount
		};

		TextureHolder						mTextures;
		FontHolder						    mFonts;
		SceneNode							mSceneGraph;
		std::array<SceneNode*, LayerCount>	mSceneLayers;
		Aircraft* mPlayerAircraft;


		//bool					mIsMovingUp;
		//bool					mIsMovingDown;
		//bool					mIsMovingRight;
		//bool					mIsMovingLeft;

		//void								loadTextures();
		//void								buildScene();


};


#endif 