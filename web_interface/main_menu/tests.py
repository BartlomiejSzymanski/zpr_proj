from django.test import TestCase,  Client
class GameOptionsViewTest(TestCase):
    def setUp(self):
        self.client = Client()
        self.url = 'http://127.0.0.1:8000/main_menu/game-options/'

    def test_game_options_view(self):
        response = self.client.get(self.url)
        self.assertEqual(response.status_code, 200)
        self.assertTemplateUsed(response, 'game_options.html')