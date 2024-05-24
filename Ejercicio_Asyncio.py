import asyncio
import aiohttp
async def fetch(url, session):
	async with session.get(url) as response:
		print(f"Status: {response.status}")
		data = await response.text()
		print(f"Data from {url} fetched")
		return data
async def main(urls):
	async with aiohttp.ClientSession() as session:
		tasks = [fetch(url, session) for url in urls]
		await asyncio.gather(*tasks)
urls = ["http://example.com"] * 5 # Lista de URLs a consultar
asyncio.run(main(urls))
